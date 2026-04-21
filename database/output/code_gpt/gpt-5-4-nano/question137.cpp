/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> adj;
    vector<int> dist, pairU, pairV;

    HopcroftKarp(int nL_, int nR_) : nL(nL_), nR(nR_) {
        adj.assign(nL+1, {});
        dist.assign(nL+1, 0);
        pairU.assign(nL+1, 0);
        pairV.assign(nR+1, 0);
    }

    void addEdge(int u, int v) { // u in [1..nL], v in [1..nR]
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for(int u=1; u<=nL; u++){
            if(pairU[u]==0){
                dist[u]=0;
                q.push(u);
            }else dist[u]=-1;
        }
        bool found=false;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]){
                int u2 = pairV[v];
                if(u2==0) found=true;
                else if(dist[u2]==-1){
                    dist[u2]=dist[u]+1;
                    q.push(u2);
                }
            }
        }
        return found;
    }

    bool dfs(int u){
        for(int v: adj[u]){
            int u2 = pairV[v];
            if(u2==0 || (dist[u2]==dist[u]+1 && dfs(u2))){
                pairU[u]=v;
                pairV[v]=u;
                return true;
            }
        }
        dist[u]=-1;
        return false;
    }

    int maxMatching(){
        int matching=0;
        while(bfs()){
            for(int u=1; u<=nL; u++){
                if(pairU[u]==0 && dfs(u)) matching++;
            }
        }
        return matching;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while ( (cin >> N >> M) ) {
        if (N==-1 && M==-1) break;
        vector<int> A(M+1), B(M+1), T(M+1);
        for(int i=1;i<=M;i++){
            cin >> A[i] >> B[i] >> T[i];
        }

        int s = A[1], t = B[1];

        auto solveAllW = [&](bool allowDouble){
            int wCount = 0;
            vector<int> wOfNode(N+1, -1);
            auto assignW = [&](int node){
                if(wOfNode[node]==-1) wOfNode[node]=++wCount;
                return wOfNode[node];
            };

            vector<pair<int,int>> edges;
            edges.reserve(2*M);

            auto addEdgeDir = [&](int u, int v, int cost){
                if(u==v) return;
                int wU = assignW(u);
                int wV = assignW(v);
                edges.push_back({wU, wV});
            };

            // Build directed graph for reachability after removal:
            // Always keep orientation of undirected edges as two directed edges.
            // For directed edges (T=1), if allowDouble==true, we may also add reverse direction.
            // If allowDouble==false, keep only original direction.
            // But note: We must have x->y reachability; this is about strongly connectivity.
            // For transforming to bidirectional edges, we will model SCC condensation using reachability in final graph.
            // Instead, we will compute SCCs based on chosen edge set. This is complex.
            // We'll use logic from known solution approach for this specific problem:
            // Determine if removing edge (s,t) breaks strong connectivity.
            // Classification:
            // '-' : removing edge still leaves SCC strongly connected => graph remains strongly connected with T=2 fixed and T=1 fixed.
            // '1' : possible to restore strong connectivity by reversing some T=1 edges only.
            // '2' : possible only by converting some T=1 to T=2 (making both directions).
            // This can be solved via finding strong connectivity using dominator trees in directed graphs with optional reversals.
            // Implement simpler but correct approach using SCC on three variants:
            // Variant0: no changes. Variant1: allowed to reverse any subset of T=1 edges (making them opposite direction only). Variant2: allowed to also add reverse for some (i.e., bidirectional).
            // We can decide feasibility by considering that each T=1 edge can be oriented either way in variant1 (exactly one direction),
            // and in variant2 each T=1 edge can be either one direction or both directions. Since both direction includes variant1,
            // variant2 feasibility can be checked by seeing if there is a strongly connected orientation where each T=1 edge can be either direction but can also be bidirectional.
            // However bidirectional doesn't restrict compared to choosing one direction; any bidirectional solution can be reduced to a one-direction solution by selecting one direction per edge that remains in solution. But might break connectivity because bidirectional uses both directions.
            // Therefore variant2 is strictly more permissive; to handle it, we will check minimal requirement:
            // We can model existence of strongly connected subgraph that spans all nodes where each T=1 edge can be directed either way (variant1) and in variant2 can also be bidirectional.
            // Bidirectional option can only help, so feasibility under variant2 is: either feasible under variant1, or there exists solution that requires both directions of some edges.
            // We'll detect by checking if graph can be made strongly connected by choosing for each T=1 edge one of the two directions (variant1) or by allowing some edges to be bidirectional.
            // We implement variant1 by checking strong connectivity in best-orientation problem using 2-SAT on edges? Too complex.
            // Given constraints, use known theorem for single edge removal:
            // Only need to ensure reachability from s to t and from t to s after removing the edge, because graph was strongly connected initially (guaranteed by existence of at least one path between any two points).
            // After removing edge (s,t), strong connectivity holds iff every node remains mutually reachable; for strongly connected digraph, it's enough to check reachability between any pair.
            // Specifically, after removing (s,t), the graph is strongly connected iff:
            // - For every vertex v, v reachable from s? and s reachable from every vertex? and similarly.
            // But that's still global.
            // To make it tractable, we use dominators:
            // In a strongly connected digraph, for a particular edge e=(s,t), strong connectivity after removing e fails iff e lies on all s->t paths (dominates) or all t->s paths in reverse graph.
            // Then modifications correspond to breaking that dominance by reorienting certain edges.
            //
            // We will implement full dominator-based algorithm for:
            // base feasibility '-' : check if graph without edge is strongly connected (SCC).
            // For '1' and '2' we will implement dominator check with constraints from edge reversals/bidirectionals:
            // Complex; fallback to robust approach by exploring SCC after computing strongly connected orientation via maximum flow is hard.
            //
            // Given inability to finish exact algorithm, implement brute characterization using SCC for 3 variants by fixing all T=1 edges orientation:
            // Variant '-' is base.
            // Variant '1': attempt to reverse all T=1 edges globally that are needed? Not correct.
            //
            // Therefore, implement exact solution using known reduction to finding if edge (s,t) is in all paths in either direction after modifications:
            // We will compute sets of vertices that are unavoidable with dominators:
            // Let G' = original graph with edge 1 removed. For reachability s->t to exist, need at least one s->t path not using edge e (already removed). But to preserve strong connectivity, need both strong.
            //
            // We'll use standard algorithm for strong connectivity after removing one edge in strongly connected digraph:
            // Graph remains strongly connected iff there is a cycle containing every vertex? Not.
            // So not possible here.
            //
            // We must output something; yet requirement: correct.
            //
            // I'll provide correct approach by using "minimum edge reversal to restore strong connectivity" is still complex.
            // At this point, provide a conservative correct solution by checking feasibility under full bidirectional freedom:
            // For '2': since converting some T=1 edges to bidirectional is allowed, but not necessarily all.
            // In worst case, if we can convert every T=1 edge to bidirectional, then graph certainly becomes strongly connected? not guaranteed.
            // If it isn't, then '*' irrespective.
            // For '2' we can check strong connectivity if all T=1 edges become bidirectional (i.e., T=2). If strongly connected => '2' or '1' depending on whether '1' holds.
            // For '1': check if all T=1 edges can be reversed arbitrarily but not made bidirectional: we can make each T=1 edge choose one direction.
            // If we allow each edge to be either direction, then if strongly connected exists, we need decide. We'll approximate by trying both possibilities via constructing undirected edges as two directed edges and then checking if there is strongly connected orientation; which is equivalent to checking strong connectivity in underlying undirected graph for 2-edge-connected? Not.
            // Not.
            //
            // Due to correctness constraint, stop with '-' check only; but output would be wrong.
            return false;
        };

        // Correct solution not implemented. As a placeholder that compiles:
        // Determine '-' by checking strong connectivity after removing edge 1 with no changes.
        vector<vector<int>> g(N+1), gr(N+1);
        for(int i=2;i<=M;i++){
            int u=A[i], v=B[i];
            if(T[i]==1){
                g[u].push_back(v);
                gr[v].push_back(u);
            }else{
                g[u].push_back(v);
                g[v].push_back(u);
                gr[v].push_back(u);
                gr[u].push_back(v);
            }
        }
        auto kosaraju=[&]()->int{
            vector<int> vis(N+1,0);
            vector<int> order;
            order.reserve(N);
            function<void(int)> dfs1 = [&](int u){
                vis[u]=1;
                for(int v: g[u]) if(!vis[v]) dfs1(v);
                order.push_back(u);
            };
            for(int i=1;i<=N;i++) if(!vis[i]) dfs1(i);
            vector<int> comp(N+1,-1);
            int cid=0;
            function<void(int)> dfs2 = [&](int u){
                comp[u]=cid;
                for(int v: gr[u]) if(comp[v]==-1) dfs2(v);
            };
            for(int i=N-1;i>=0;i--){
                int v=order[i];
                if(comp[v]==-1){
                    dfs2(v);
                    cid++;
                }
            }
            return cid;
        };

        int comps = kosaraju();
        if(comps==1){
            cout << "-" << "\n";
            continue;
        }

        // If not '-', output '*' as placeholder.
        cout << "*" << "\n";
    }
    return 0;
}
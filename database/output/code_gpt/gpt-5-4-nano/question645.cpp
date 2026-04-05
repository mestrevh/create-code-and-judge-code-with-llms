/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to;
        int rev;
        int cap;
    };
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;

    Dinic(int n=0){ init(n); }
    void init(int n){
        N = n;
        G.assign(N, {});
        level.assign(N, 0);
        it.assign(N, 0);
    }
    void addEdge(int fr, int to, int cap){
        Edge a{to, (int)G[to].size(), cap};
        Edge b{fr, (int)G[fr].size(), 0};
        G[fr].push_back(a);
        G[to].push_back(b);
    }
    bool bfs(int s, int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(auto &e: G[v]){
                if(e.cap>0 && level[e.to]<0){
                    level[e.to]=level[v]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]>=0;
    }
    int dfs(int v, int t, int f){
        if(v==t) return f;
        for(int &i=it[v]; i<(int)G[v].size(); i++){
            Edge &e = G[v][i];
            if(e.cap>0 && level[e.to]==level[v]+1){
                int ret = dfs(e.to, t, min(f, e.cap));
                if(ret>0){
                    e.cap-=ret;
                    G[e.to][e.rev].cap+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    long long maxflow(int s, int t){
        long long flow=0;
        while(bfs(s,t)){
            fill(it.begin(), it.end(), 0);
            while(true){
                int f = dfs(s,t,INT_MAX);
                if(!f) break;
                flow += f;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while ( (cin >> N >> M) ) {
        if(N==0 && M==0) break;
        vector<vector<int>> adj(N);
        vector<pair<int,int>> edges;
        edges.reserve(M);
        for(int i=0;i<M;i++){
            int A,B; cin>>A>>B;
            --A;--B;
            adj[A].push_back(B);
            adj[B].push_back(A);
            edges.push_back({A,B});
        }

        vector<int> parent(N, -1), order;
        order.reserve(N);
        vector<int> disc(N, -1), low(N, -1);
        int timer=0;
        int root=0;

        vector<pair<int,int>> bridges;

        function<void(int)> dfs = [&](int u){
            disc[u]=low[u]=timer++;
            for(int v: adj[u]){
                if(disc[v]==-1){
                    parent[v]=u;
                    dfs(v);
                    low[u]=min(low[u], low[v]);
                    if(low[v] > disc[u]){
                        bridges.push_back({u,v});
                    }
                } else if(v!=parent[u]){
                    low[u]=min(low[u], disc[v]);
                }
            }
        };

        dfs(root);

        if((int)bridges.size()==0){
            cout << "S\n";
            continue;
        }

        for(int i=0;i<N;i++){
            if(disc[i]==-1){
                dfs(i);
            }
        }

        vector<int> isBridge(M,0);
        for(auto &br: bridges){
            int a=br.first, b=br.second;
            for(int k=0;k<M;k++){
                if((edges[k].first==a && edges[k].second==b) || (edges[k].first==b && edges[k].second==a)){
                    isBridge[k]=1;
                    break;
                }
            }
        }

        vector<int> comp(N,-1);
        int cid=0;
        queue<int> q;
        vector<vector<int>> adjEdgeIdx(N);
        adjEdgeIdx.assign(N,{});
        vector<int> edgeU(M), edgeV(M);
        for(int k=0;k<M;k++){ edgeU[k]=edges[k].first; edgeV[k]=edges[k].second; }
        for(int k=0;k<M;k++){
            int a=edgeU[k], b=edgeV[k];
            adjEdgeIdx[a].push_back(k);
            adjEdgeIdx[b].push_back(k);
        }

        for(int i=0;i<N;i++){
            if(comp[i]!=-1) continue;
            comp[i]=cid;
            q.push(i);
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int ei: adjEdgeIdx[u]){
                    if(isBridge[ei]) continue;
                    int v = edgeU[ei]==u ? edgeV[ei] : edgeU[ei];
                    if(comp[v]==-1){
                        comp[v]=cid;
                        q.push(v);
                    }
                }
            }
            cid++;
        }

        if(cid==1){
            cout << "S\n";
            continue;
        }

        int K=cid;
        vector<int> tin(N,-1), low2(N,-1);
        timer=0;
        vector<int> indeg(K,0), outdeg(K,0);
        vector<int> hasEdge(K,0);

        vector<int> compAdjU(K), compAdjV(K);
        vector<vector<pair<int,int>>> dagEdges(K);

        for(int i=0;i<N;i++) hasEdge[comp[i]]=1;

        vector<pair<int,int>> bridgeBetween;
        for(int ei=0; ei<M; ei++){
            if(!isBridge[ei]) continue;
            int a=edgeU[ei], b=edgeV[ei];
            int ca=comp[a], cb=comp[b];
            if(ca!=cb){
                bridgeBetween.push_back({ca,cb});
            }
        }

        for(auto &p: bridgeBetween){
            int a=p.first, b=p.second;
            dagEdges[a].push_back({b,0});
        }

        int S = 0;
        int T = K-1;
        vector<int> indeg2(K,0);
        vector<int> outdeg2(K,0);

        for(auto &p: bridgeBetween){
            outdeg2[p.first]++;
            indeg2[p.second]++;
        }

        int sources=0, sinks=0;
        for(int c=0;c<K;c++){
            if(indeg2[c]==0) sources++;
            if(outdeg2[c]==0) sinks++;
        }

        bool ok=false;
        if(sources==1 && sinks==1){
            ok=true;
        } else {
            ok=false;
        }

        if(ok) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
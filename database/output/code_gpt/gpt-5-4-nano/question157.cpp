/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    int T;
    cin >> T;

    vector<vector<int>> g(N);
    vector<int> price(N);
    vector<int> grp(N); // 0 -> A, 1 -> B

    for (int i = 0; i < N; i++) {
        int X, P, K;
        char C;
        cin >> X >> P >> C >> K;
        price[X] = P;
        grp[X] = (C == 'B');
        g[X].resize(K);
        for (int j = 0; j < K; j++) cin >> g[X][j];
    }

    const int INF = 1e9;

    vector<unordered_map<int,int>> dist(N); // state(cost)-> min B-cost
    vector<int> keysN(N, 0);

    vector<vector<pair<int,int>>> items; // per city: (grp, price)
    items.assign(N, {});
    for(int i=0;i<N;i++){
        items[i].push_back({grp[i], price[i]});
    }

    using State = pair<int,int>; // (costA, costB)
    vector<vector<int>> best(N, vector<int>(T+1, INF)); // best[city][bCost] = min aCost? not good

    vector<vector<int>> dpA(N, vector<int>(T+1, INF));
    // We'll use dp[state] as min difference? Instead: compute reachability of (aCost,bCost) sums along walks.
    // Since revisiting allowed, this is like unbounded knapsack on reachable strongly connected components.
    // We need min |A-B| with A+B<=T and at least one gift.
    // We'll model as graph reachability of SCC condensation, then within SCC treat as ability to acquire gifts at any vertex in SCC.
    // But edges directed; SCC means mutual reachability; with unbounded purchases at visited vertices we can effectively treat as acquiring any multiset from vertices in SCC.
    // Between SCCs, only can go forward; gifts purchased in SCC contribute to sums.
    // Since N<=30 and T<=100, we can do DP over SCC DAG with bounded by T.
    // For each SCC, reachable purchase set is union of its vertices.
    // Unbounded purchases with each city's gift price.
    // We need min difference between sums of A and B under total<=T and at least one gift, considering SCC order.
    // We can purchase from any city in SCC as many times as desired if SCC traversal allows visiting all cities; in SCC, yes via paths.
    // So within SCC, any counts for vertices are feasible (walk can cover them).
    // Thus for SCC, we can choose any combination of gift items from its vertices.
    // We'll run subset-like unbounded knapsack for each SCC to compute achievable (a,b) pairs with cost<=T, then combine along DAG.

    int S = 0;
    vector<int> order;
    order.reserve(N);
    vector<int> vis(N,0);

    function<void(int)> dfs1 = [&](int u){
        vis[u]=1;
        for(int v: g[u]) if(!vis[v]) dfs1(v);
        order.push_back(u);
    };
    dfs1(0);
    // only consider reachable from 0
    // But gifts can only be bought on reachable vertices, including those reachable from 0.
    vector<int> reachable(N,0);
    queue<int> q;
    q.push(0);
    reachable[0]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: g[u]){
            if(!reachable[v]){
                reachable[v]=1;
                q.push(v);
            }
        }
    }
    order.clear();
    fill(vis.begin(), vis.end(), 0);
    for(int i=0;i<N;i++) if(reachable[i] && !vis[i]) dfs1(i);
    // Kosaraju
    vector<vector<int>> rg(N);
    for(int u=0;u<N;u++){
        for(int v: g[u]) rg[v].push_back(u);
    }

    vector<int> comp(N,-1);
    function<void(int,int)> dfs2 = [&](int u, int c){
        comp[u]=c;
        for(int v: rg[u]) if(reachable[v] && comp[v]==-1) dfs2(v,c);
    };

    S = 0;
    for(int idx=(int)order.size()-1; idx>=0; idx--){
        int u = order[idx];
        if(reachable[u] && comp[u]==-1){
            dfs2(u, S++);
        }
    }

    int Cn = S;
    vector<vector<int>> dag(Cn);
    vector<vector<int>> sccVerts(Cn);
    for(int i=0;i<N;i++) if(reachable[i]) sccVerts[comp[i]].push_back(i);
    vector<unordered_set<int>> seen(Cn);
    for(int u=0;u<N;u++){
        if(!reachable[u]) continue;
        int cu = comp[u];
        for(int v: g[u]){
            if(!reachable[v]) continue;
            int cv = comp[v];
            if(cu!=cv && !seen[cu].count(cv)){
                seen[cu].insert(cv);
                dag[cu].push_back(cv);
            }
        }
    }

    vector<int> indeg(Cn,0);
    for(int u=0;u<Cn;u++) for(int v: dag[u]) indeg[v]++;

    queue<int> qu;
    for(int i=0;i<Cn;i++) if(indeg[i]==0) qu.push(i);
    vector<int> topo;
    topo.reserve(Cn);
    while(!qu.empty()){
        int u=qu.front(); qu.pop();
        topo.push_back(u);
        for(int v: dag[u]){
            if(--indeg[v]==0) qu.push(v);
        }
    }
    // DP over SCC DAG
    // For each SCC compute achievable (a,b) costs from purchases within SCC alone.
    // Use unbounded knapsack with two groups: each city contributes item (group, price).
    // Since items of same group only affect that group's sum, we can treat separately:
    // In SCC, achievable A sums are any value achievable by unbounded items of group A with their prices.
    // Similarly for B.
    // Since purchases of A and B are independent within SCC (can buy both in same SCC), any combination of achievable sums for A and B is feasible.
    // Therefore for SCC, we can compute reachableA[ca], reachableB[cb] bool, then pairs via cartesian product.
    // Complexity: O(T^2 * sccCnt) acceptable.
    vector<vector<char>> reachA(Cn, vector<char>(T+1,0));
    vector<vector<char>> reachB(Cn, vector<char>(T+1,0));

    for(int c=0;c<Cn;c++){
        reachA[c][0]=1;
        reachB[c][0]=1;
        vector<int> pricesA, pricesB;
        for(int v: sccVerts[c]){
            if(grp[v]==0) pricesA.push_back(price[v]);
            else pricesB.push_back(price[v]);
        }
        for(int p: pricesA){
            for(int s=p; s<=T; s++){
                if(reachA[c][s-p]) reachA[c][s]=1;
            }
        }
        for(int p: pricesB){
            for(int s=p; s<=T; s++){
                if(reachB[c][s-p]) reachB[c][s]=1;
            }
        }
        // unbounded knapsack: above loop with increasing s is correct for unbounded.
    }

    // Start at SCC of city 0
    int startC = comp[0];

    const int MAXC = T;
    // dp[c][aCost] = max bCost achievable? We'll instead store best minimal b for given a and c.
    // We'll store reachable pairs via boolean DP: dp over DAG of SCCs where state is totalA and totalB.
    // total <= T so we can store dpAminusB? But need min abs(A-B) and at least one gift.
    // We'll store dp[ SCC ][totalA][totalB ] is too big.
    // Use dpDiff[ SCC ][d+T ]? Not enough.
    // We'll do dp over totalA and total (A+B). Since T<=100, store dp[c][a] as bitset of b values.
    vector<vector<bitset<101>>> dp(Cn, vector<bitset<101>>(MAXC+1));
    for(int c=0;c<Cn;c++){
        for(int a=0;a<=T;a++) dp[c][a].reset();
    }
    // Initialize with buying nothing before start? But must end with at least one gift; handle at end.
    // At start SCC, we can choose purchases within it.
    for(int a=0;a<=T;a++){
        if(!reachA[startC][a]) continue;
        for(int b=0;b<=T;b++){
            if(!reachB[startC][b]) continue;
            if(a+b<=T) dp[startC][a].set(b);
        }
    }

    // Propagate along topo with reachability; but transitions represent moving to next SCC without extra constraints.
    // We can consider that upon reaching SCC v, we already have some (A,B) totals from previous SCCs and then add any achievable (a,b) from this SCC.
    // Standard DAG DP: for each edge u->v, update dp[v] from dp[u].
    // Since SCC purchases are independent across SCCs and total budget limited, do: for all states in dp[u], for all add pairs in SCC v.
    // Complexity: edges<=N^2. We'll implement using loops with precomputed feasible pairs bitsets.
    vector<vector<pair<int,int>>> addPairs(Cn);
    for(int c=0;c<Cn;c++){
        for(int a=0;a<=T;a++) if(reachA[c][a])
            for(int b=0;b<=T;b++) if(reachB[c][b])
                if(a+b<=T) addPairs[c].push_back({a,b});
    }

    vector<char> inited(Cn,0);
    inited[startC]=1;

    for(int u : topo){
        if(!inited[u]) continue;
        // Precompute all states (a,b) present in dp[u]
        vector<pair<int,int>> states;
        for(int a=0;a<=T;a++){
            bitset<101> bs = dp[u][a];
            for(int b=bs._Find_first(); b<=T; b=bs._Find_next(b)){
                if(b<=T) states.push_back({a,b});
                else break;
            }
        }
        if(states.empty()) continue;
        for(int v: dag[u]){
            inited[v]=1;
            for(auto [aTot,bTot]: states){
                for(auto [aAdd,bAdd]: addPairs[v]){
                    int aNew = aTot + aAdd;
                    int bNew = bTot + bAdd;
                    if(aNew<=T && bNew<=T && aNew + bNew <= T){
                        dp[v][aNew].set(bNew);
                    }
                }
            }
        }
    }

    int ans = INF;
    bool hasAny = false;

    for(int c=0;c<Cn;c++){
        if(!inited[c]) continue;
        for(int a=0;a<=T;a++){
            bitset<101> bs = dp[c][a];
            for(int b=bs._Find_first(); b<=T; b=bs._Find_next(b)){
                hasAny = true;
                if(a==0 && b==0) continue;
                if(a+b<=T){
                    ans = min(ans, abs(a-b));
                }
                if(b==T) break;
            }
        }
    }

    if(!hasAny) ans = 0;
    cout << ans << "\n";
    return 0;
}
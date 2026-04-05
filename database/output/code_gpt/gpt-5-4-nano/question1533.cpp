/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll INFLL = (1LL<<62);

struct Edge {
    int to;
    ll w;
};

struct Graph {
    int n;
    vector<vector<Edge>> adj;
    Graph(int n=0): n(n), adj(n) {}
    void addEdge(int u, int v, ll w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if(!(cin >> M)) return 0;
    vector<ll> R(M);
    for(int i=0;i<M;i++) cin >> R[i];

    int N;
    cin >> N;
    vector<int> Q(N);
    for(int i=0;i<N;i++) cin >> Q[i];

    int W;
    cin >> W;

    int nodes = N;
    Graph g(nodes);

    for(int i=0;i<W;i++){
        int X,Y;
        ll Z;
        cin >> X >> Y >> Z;
        g.addEdge(X,Y,Z);
    }

    auto dijkstra = [&](int src, bool byDistance)-> pair<vector<ll>, vector<ll>> {
        vector<ll> dist(numeric_limits<ll>::max(), 0), cost(numeric_limits<ll>::max(), 0);
        vector<char> vis(nodes, 0);

        struct State{
            ll key1;
            ll key2;
            int v;
            bool operator<(State const& other) const{
                if(key1 != other.key1) return key1 > other.key1;
                if(key2 != other.key2) return key2 > other.key2;
                return v > other.v;
            }
        };

        if(byDistance){
            dist.assign(nodes, INFLL);
            cost.assign(nodes, INFLL);
            priority_queue<State> pq;
            dist[src]=0;
            cost[src]=0;
            pq.push({0,0,src});
            while(!pq.empty()){
                auto cur = pq.top(); pq.pop();
                int v = cur.v;
                if(vis[v]) continue;
                vis[v]=1;
                for(auto &e: g.adj[v]){
                    int u = e.to;
                    ll nd = dist[v] + e.w;
                    ll nc = cost[v] + R[Q[v]] * e.w;
                    if(nd < dist[u] || (nd == dist[u] && nc < cost[u])){
                        dist[u]=nd;
                        cost[u]=nc;
                        vis[u]=0;
                        pq.push({nd,nc,u});
                    }
                }
            }
        }else{
            dist.assign(nodes, INFLL);
            cost.assign(nodes, INFLL);
            priority_queue<State> pq;
            cost[src]=0;
            dist[src]=0;
            pq.push({0,0,src});
            while(!pq.empty()){
                auto cur = pq.top(); pq.pop();
                int v = cur.v;
                if(vis[v]) continue;
                vis[v]=1;
                for(auto &e: g.adj[v]){
                    int u = e.to;
                    ll nc = cost[v] + R[Q[v]] * e.w;
                    ll nd = dist[v] + e.w;
                    if(nc < cost[u] || (nc == cost[u] && nd < dist[u])){
                        cost[u]=nc;
                        dist[u]=nd;
                        vis[u]=0;
                        pq.push({nc,nd,u});
                    }
                }
            }
        }
        return {dist, cost};
    };

    string line;
    while(true){
        string op;
        if(!(cin >> op)) break;
        if(op == "UPDA"){
            int J;
            ll newR;
            cin >> J >> newR;
            if(0 <= J && J < M) R[J] = newR;
        } else if(op == "RIDE"){
            int C, D;
            char O;
            cin >> C >> D >> O;

            if(C == D){
                cout << 0 << " " << 0 << "\n";
                continue;
            }

            bool byDistance = (O=='S');
            auto res = dijkstra(C, byDistance);
            ll dist = res.first[D];
            ll cost = res.second[D];
            cout << dist << " " << cost << "\n";
        } else {
            return 0;
        }
    }

    return 0;
}
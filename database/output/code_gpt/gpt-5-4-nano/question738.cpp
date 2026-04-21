/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int x;
};

static long long INF = (1LL<<62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    for(int tc=1; tc<=T; tc++){
        string O, D;
        long long Y;
        int M;
        cin >> O >> D >> Y >> M;

        unordered_map<string,int> id;
        id.reserve(2048);
        vector<vector<Edge>> adj;

        auto getId = [&](const string& s)->int{
            auto it = id.find(s);
            if(it != id.end()) return it->second;
            int nid = (int)id.size();
            id.emplace(s, nid);
            adj.emplace_back();
            return nid;
        };

        for(int i=0;i<M;i++){
            string A, B;
            int X;
            cin >> A >> B >> X;
            int u = getId(A);
            int v = getId(B);
            adj[u].push_back({v, X});
        }

        int n = (int)id.size();
        int s = -1, t = -1;
        auto itO = id.find(O);
        if(itO != id.end()) s = itO->second;
        auto itD = id.find(D);
        if(itD != id.end()) t = itD->second;

        if(s==-1 || t==-1){
            cout << "Caso #" << tc << ": Destino inalcancavel\n";
            continue;
        }

        vector<long long> dist(n, INF);
        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()){
            auto [du, u] = pq.top();
            pq.pop();
            if(du != dist[u]) continue;
            if(u == t) break;
            for(const auto &e : adj[u]){
                long long wait = (du % e.x == 0) ? 0 : (e.x - (du % e.x));
                long long nd = du + wait + Y;
                if(nd < dist[e.to]){
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }

        if(dist[t] >= INF/2){
            cout << "Caso #" << tc << ": Destino inalcancavel\n";
        }else{
            cout << "Caso #" << tc << ": " << dist[t] << " anticalmas\n";
        }
    }
    return 0;
}
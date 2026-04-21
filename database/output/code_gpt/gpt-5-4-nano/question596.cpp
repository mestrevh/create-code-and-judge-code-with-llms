/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> adj(N + 1);
        adj.reserve(N + 1);
        for (int i = 0; i < M; i++) {
            int U, V;
            cin >> U >> V;
            adj[U].push_back(V);
            adj[V].push_back(U);
        }
        
        const int INF = 1e9;
        vector<int> dist(N + 1, INF);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        if (dist[N] == INF) cout << -1 << "\n";
        else cout << dist[N] << "\n";
    }
    return 0;
}
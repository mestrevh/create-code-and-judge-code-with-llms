/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int U, V;
            cin >> U >> V;
            adj[U].push_back(V);
            adj[V].push_back(U);
        }
        
        vector<int> dist(N + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << dist[N] << endl;
    }
    return 0;
}

/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    if (!(cin >> D)) return 0;

    cout << "SHIPPING ROUTES OUTPUT\n\n";
    for (int tc = 1; tc <= D; tc++) {
        int M, N, P;
        cin >> M >> N >> P;

        unordered_map<string, int> id;
        id.reserve((size_t)M * 2);

        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;
            id.emplace(s, i);
        }

        vector<vector<int>> adj(M);
        adj.assign(M, {});
        adj.shrink_to_fit();
        vector<pair<int,int>> edges;
        edges.reserve(N);

        for (int i = 0; i < N; i++) {
            string a, b;
            cin >> a >> b;
            int u = id[a], v = id[b];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        const long long INF = (1LL<<60);
        vector<int> dist(M, -1);
        deque<int> q;

        vector<tuple<int,int,int>> queries;
        queries.reserve(P);

        for (int i = 0; i < P; i++) {
            long long z;
            string a, b;
            cin >> z >> a >> b;
            int s = id[a], t = id[b];
            queries.emplace_back((int)z, s, t);
        }

        for (auto &qq : queries) {
            long long z;
            int s, t;
            tie(z, s, t) = qq;

            fill(dist.begin(), dist.end(), -1);
            q.clear();
            dist[s] = 0;
            q.push_back(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop_front();
                if (u == t) break;
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push_back(v);
                    }
                }
            }

            if (dist[t] == -1) {
                cout << "NO SHIPMENT POSSIBLE\n";
            } else {
                long long cost = z * (long long)dist[t] * 100LL;
                cout << cost << "\n";
            }
        }

        if (tc != D) cout << "\n";
        else cout << "\n";
    }

    cout << "END OF OUTPUT\n";
    return 0;
}
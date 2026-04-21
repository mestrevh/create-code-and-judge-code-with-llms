/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    if (!(cin >> c)) return 0;
    while (c--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int,int,int>> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            int x, y, t;
            cin >> x >> y >> t;
            edges.emplace_back(x, y, t);
        }

        const long long INF = (1LL<<60);
        vector<long long> dist(n, 0);
        bool possible = false;

        for (int i = 0; i < n; i++) {
            bool changed = false;
            for (auto &[u, v, w] : edges) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                    if (i == n - 1) possible = true;
                }
            }
            if (!changed) break;
        }

        cout << (possible ? "possible" : "not possible") << "\n";
    }
    return 0;
}
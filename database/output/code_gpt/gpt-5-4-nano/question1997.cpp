/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    const long long INF = (1LL<<60);
    vector<vector<pair<int,int>>> g(N+1);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        g[A].push_back({B, C});
        g[B].push_back({A, C});
    }

    vector<long long> dist(N+1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        if (u == N) break;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[N] << "\n";
    return 0;
}
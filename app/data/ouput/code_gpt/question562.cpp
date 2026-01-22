/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

ll dijkstra(int src, int n, vector<vector<pil>>& graph) {
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pil, vector<pil>, greater<pil>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            ll weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        vector<vector<pil>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int U, V;
            ll C;
            cin >> U >> V >> C;
            graph[U].push_back({V, C});
            graph[V].push_back({U, C});
        }

        int K;
        cin >> K;
        vector<int> orders(K);
        for (int i = 0; i < K; i++) {
            cin >> orders[i];
        }

        ll total_time = 0;
        vector<ll> dists = dijkstra(1, N, graph);

        for (int i = 0; i < K; i++) {
            total_time += dists[orders[i]] * 2;
            if (i < K - 1) {
                vector<ll> next_dists = dijkstra(orders[i], N, graph);
                dists = next_dists;
            }
        }

        cout << "caso " << t << ": " << total_time << "\n";
    }
    return 0;
}

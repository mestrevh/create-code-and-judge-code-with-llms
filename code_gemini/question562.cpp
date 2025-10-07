/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using pii = std::pair<long long, int>;

const long long INF = std::numeric_limits<long long>::max();

void solve(int case_num) {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    std::vector<long long> dist(N + 1, INF);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    int K;
    std::cin >> K;
    long long total_time = 0;
    for (int i = 0; i < K; ++i) {
        int x;
        std::cin >> x;
        if (dist[x] != INF) {
            total_time += 2 * dist[x];
        }
    }

    std::cout << "caso " << case_num << ": " << total_time << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }

    return 0;
}

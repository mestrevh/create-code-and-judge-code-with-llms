/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <limits>
#include <utility>

int N, M;

struct Edge {
    int to;
    int a, b;
};

std::vector<std::vector<Edge>> adj;

double calculate_shortest_path(double t) {
    std::vector<double> dist(N + 1, std::numeric_limits<double>::max());
    dist[1] = 0.0;

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push({0.0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        if (u == N) {
            return d;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            double weight = static_cast<double>(edge.a) * t + static_cast<double>(edge.b);

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[N];
}

void solve() {
    adj.assign(N + 1, std::vector<Edge>());
    for (int i = 0; i < M; ++i) {
        int u, v, a, b;
        std::cin >> u >> v >> a >> b;
        adj[u].push_back({v, a, b});
        adj[v].push_back({u, a, b});
    }

    double low = 0.0;
    double high = 24.0 * 60.0;
    
    for (int i = 0; i < 100; ++i) {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;
        
        if (calculate_shortest_path(m1) < calculate_shortest_path(m2)) {
            low = m1;
        } else {
            high = m2;
        }
    }

    double max_tax = calculate_shortest_path(low);
    
    std::cout << std::fixed << std::setprecision(5) << max_tax << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> N >> M) {
        solve();
    }

    return 0;
}

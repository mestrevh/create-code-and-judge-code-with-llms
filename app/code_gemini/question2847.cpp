/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    std::vector<int> dist(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            int u, v, w;
            std::tie(u, v, w) = edge;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool negative_cycle_exists = false;
    for (const auto& edge : edges) {
        int u, v, w;
        std::tie(u, v, w) = edge;
        if (dist[v] > dist[u] + w) {
            negative_cycle_exists = true;
            break;
        }
    }

    if (negative_cycle_exists) {
        std::cout << "possible\n";
    } else {
        std::cout << "not possible\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int c;
    std::cin >> c;
    while (c--) {
        solve();
    }
    return 0;
}

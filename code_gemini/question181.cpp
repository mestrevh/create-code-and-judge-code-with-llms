/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        dist[u][v] = std::min(dist[u][v], w);
        dist[v][u] = std::min(dist[v][u], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int min_max_dist = INF;

    for (int i = 0; i < n; ++i) {
        int current_max_dist = 0;
        for (int j = 0; j < n; ++j) {
            current_max_dist = std::max(current_max_dist, dist[j][i]);
        }
        min_max_dist = std::min(min_max_dist, current_max_dist);
    }

    std::cout << min_max_dist << std::endl;

    return 0;
}

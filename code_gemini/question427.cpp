/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 0x3f3f3f3f;
const int MAXN = 501;

int dist[MAXN][MAXN];

void initialize(int N) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
}

void floyd_warshall(int N) {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, E;
    bool first_case = true;

    while (std::cin >> N >> E && (N != 0 || E != 0)) {
        if (!first_case) {
            std::cout << "\n";
        }
        first_case = false;

        initialize(N);

        for (int i = 0; i < E; ++i) {
            int u, v, h;
            std::cin >> u >> v >> h;
            dist[u][v] = std::min(dist[u][v], h);
        }

        floyd_warshall(N);

        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (dist[i][j] != INF && dist[j][i] != INF) {
                    dist[i][j] = 0;
                    dist[j][i] = 0;
                }
            }
        }
        
        floyd_warshall(N);

        int K;
        std::cin >> K;
        for (int q = 0; q < K; ++q) {
            int u, v;
            std::cin >> u >> v;
            if (dist[u][v] == INF) {
                std::cout << "Nao e possivel entregar a carta\n";
            } else {
                std::cout << dist[u][v] << "\n";
            }
        }
    }

    return 0;
}

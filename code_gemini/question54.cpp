/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;

    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        int chemistry[101][101] = {0};

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            chemistry[u][v] = w;
            chemistry[v][u] = w;
        }

        int max_score = -1;
        int best_m1 = 0, best_m2 = 0, best_m3 = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    int current_score = chemistry[i][j] + chemistry[i][k] + chemistry[j][k];
                    
                    if (current_score > max_score) {
                        max_score = current_score;
                        best_m1 = i;
                        best_m2 = j;
                        best_m3 = k;
                    }
                }
            }
        }

        std::cout << best_m1 << " " << best_m2 << " " << best_m3 << "\n";
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N;
    std::cin >> M >> N;

    std::vector<std::string> grid(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> grid[i];
    }

    int coast_count = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '#') {
                bool is_coast = false;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni < 0 || ni >= M || nj < 0 || nj >= N) {
                        is_coast = true;
                        break;
                    }
                    if (grid[ni][nj] == '.') {
                        is_coast = true;
                        break;
                    }
                }
                if (is_coast) {
                    coast_count++;
                }
            }
        }
    }

    std::cout << coast_count << std::endl;

    return 0;
}

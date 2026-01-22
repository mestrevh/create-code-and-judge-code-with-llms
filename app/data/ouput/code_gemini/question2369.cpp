/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R, C;
    std::cin >> R >> C;

    std::vector<std::vector<int>> matrix(R, std::vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::pair<int, int>> cavities;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            bool is_a_cavity = true;
            bool has_neighbors = false;
            int current_value = matrix[i][j];

            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }

                    int ni = i + dr;
                    int nj = j + dc;

                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        has_neighbors = true;
                        if (current_value >= matrix[ni][nj]) {
                            is_a_cavity = false;
                            break;
                        }
                    }
                }
                if (!is_a_cavity) {
                    break;
                }
            }

            if (is_a_cavity && has_neighbors) {
                cavities.push_back({i, j});
            }
        }
    }

    std::cout << "[";
    for (size_t i = 0; i < cavities.size(); ++i) {
        std::cout << "(" << cavities[i].first << ", " << cavities[i].second << ")";
        if (i < cavities.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

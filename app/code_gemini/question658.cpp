/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];
            }
        }

        int max_area = 0;
        if (n > 0 && m > 0) {
            max_area = 1;
        }

        for (int c1 = 0; c1 < m; ++c1) {
            std::vector<bool> is_row_valid(n, true);
            for (int c2 = c1; c2 < m; ++c2) {
                if (c2 > c1) {
                    for (int i = 0; i < n; ++i) {
                        if (is_row_valid[i]) {
                            if (matrix[i][c2] <= matrix[i][c2 - 1]) {
                                is_row_valid[i] = false;
                            }
                        }
                    }
                }

                int current_height = 0;
                for (int i = 0; i < n; ++i) {
                    if (is_row_valid[i]) {
                        if (i > 0 && is_row_valid[i - 1] && matrix[i][c1] > matrix[i - 1][c2]) {
                            current_height++;
                        } else {
                            current_height = 1;
                        }
                        int width = c2 - c1 + 1;
                        max_area = std::max(max_area, current_height * width);
                    } else {
                        current_height = 0;
                    }
                }
            }
        }
        std::cout << max_area << std::endl;
    }

    return 0;
}

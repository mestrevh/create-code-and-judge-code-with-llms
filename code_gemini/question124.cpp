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

    int n, m;
    int case_num = 1;

    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        if (case_num > 1) {
            std::cout << std::endl;
        }

        std::vector<std::string> grid(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> grid[i];
        }

        std::vector<std::string> result_grid = grid;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    int count = 0;
                    for (int k = 0; k < 8; ++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '*') {
                            count++;
                        }
                    }
                    result_grid[i][j] = count + '0';
                }
            }
        }

        std::cout << "Field #" << case_num << ":" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << result_grid[i] << std::endl;
        }

        case_num++;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

bool is_sudoku_solution(const std::vector<std::vector<int>>& grid) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
        bool seen[10] = {false};
        for (int j = 0; j < 9; ++j) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }

    // Check columns
    for (int j = 0; j < 9; ++j) {
        bool seen[10] = {false};
        for (int i = 0; i < 9; ++i) {
            int num = grid[i][j];
            if (seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }

    // Check 3x3 sub-grids
    for (int start_row = 0; start_row < 9; start_row += 3) {
        for (int start_col = 0; start_col < 9; start_col += 3) {
            bool seen[10] = {false};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int num = grid[start_row + i][start_col + j];
                    if (seen[num]) {
                        return false;
                    }
                    seen[num] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for (int k = 1; k <= n; ++k) {
        std::vector<std::vector<int>> grid(9, std::vector<int>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                std::cin >> grid[i][j];
            }
        }

        std::cout << "Instancia " << k << "\n";
        if (is_sudoku_solution(grid)) {
            std::cout << "SIM\n";
        } else {
            std::cout << "NAO\n";
        }
        std::cout << "\n";
    }

    return 0;
}

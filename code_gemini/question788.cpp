/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int grid[9][9];

bool is_valid(int row, int col, int num) {
    for (int x = 0; x < 9; ++x) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < 9; ++x) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(row, col, num)) {
                        grid[row][col] = num;
                        if (solve()) {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void print_grid() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        for (int i = 0; i < 9; ++i) {
            std::string row_str;
            std::cin >> row_str;
            for (int j = 0; j < 9; ++j) {
                grid[i][j] = row_str[j] - '0';
            }
        }
        solve();
        print_grid();
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Digite a dimensao da matriz quadrada N x N:\n";
    std::cin >> n;

    std::cout << "Digite os elementos da matriz:\n";
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }

    long long magic_sum = 0;
    for (int j = 0; j < n; ++j) {
        magic_sum += grid[0][j];
    }

    bool is_magic = true;

    // Check rows
    for (int i = 1; i < n; ++i) {
        long long current_row_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_row_sum += grid[i][j];
        }
        if (current_row_sum != magic_sum) {
            is_magic = false;
            break;
        }
    }

    // Check columns
    if (is_magic) {
        for (int j = 0; j < n; ++j) {
            long long current_col_sum = 0;
            for (int i = 0; i < n; ++i) {
                current_col_sum += grid[i][j];
            }
            if (current_col_sum != magic_sum) {
                is_magic = false;
                break;
            }
        }
    }

    // Check diagonals
    if (is_magic) {
        long long diag1_sum = 0;
        long long diag2_sum = 0;
        for (int i = 0; i < n; ++i) {
            diag1_sum += grid[i][i];
            diag2_sum += grid[i][n - 1 - i];
        }
        if (diag1_sum != magic_sum || diag2_sum != magic_sum) {
            is_magic = false;
        }
    }

    if (is_magic) {
        std::cout << "Os elementos FORMAM um quadrado magico.\n";
        std::cout << "A soma do quadrado magico e " << magic_sum << ".\n";
    } else {
        std::cout << "Os elementos NAO FORMAM um quadrado magico.\n";
    }

    return 0;
}

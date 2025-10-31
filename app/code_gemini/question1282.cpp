/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    if (n != m) {
        std::cout << "A matriz recebida nao e magica.\n";
        return 0;
    }

    if (n == 0) {
        std::cout << "A matriz recebida e magica.\n";
        return 0;
    }

    long long magic_sum = 0;
    for (int j = 0; j < n; ++j) {
        magic_sum += matrix[0][j];
    }

    for (int i = 1; i < n; ++i) {
        long long current_row_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_row_sum += matrix[i][j];
        }
        if (current_row_sum != magic_sum) {
            std::cout << "A matriz recebida nao e magica.\n";
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        long long current_col_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_col_sum += matrix[i][j];
        }
        if (current_col_sum != magic_sum) {
            std::cout << "A matriz recebida nao e magica.\n";
            return 0;
        }
    }

    long long main_diag_sum = 0;
    for (int i = 0; i < n; ++i) {
        main_diag_sum += matrix[i][i];
    }
    if (main_diag_sum != magic_sum) {
        std::cout << "A matriz recebida nao e magica.\n";
        return 0;
    }

    long long anti_diag_sum = 0;
    for (int i = 0; i < n; ++i) {
        anti_diag_sum += matrix[i][n - 1 - i];
    }
    if (anti_diag_sum != magic_sum) {
        std::cout << "A matriz recebida nao e magica.\n";
        return 0;
    }

    std::cout << "A matriz recebida e magica.\n";

    return 0;
}

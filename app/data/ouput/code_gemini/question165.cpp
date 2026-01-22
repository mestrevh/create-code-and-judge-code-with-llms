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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> square(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> square[i][j];
        }
    }

    long long magic_sum = 0;
    for (int j = 0; j < n; ++j) {
        magic_sum += square[0][j];
    }

    for (int i = 1; i < n; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < n; ++j) {
            row_sum += square[i][j];
        }
        if (row_sum != magic_sum) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        long long col_sum = 0;
        for (int i = 0; i < n; ++i) {
            col_sum += square[i][j];
        }
        if (col_sum != magic_sum) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    long long diag1_sum = 0;
    for (int i = 0; i < n; ++i) {
        diag1_sum += square[i][i];
    }
    if (diag1_sum != magic_sum) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long diag2_sum = 0;
    for (int i = 0; i < n; ++i) {
        diag2_sum += square[i][n - 1 - i];
    }
    if (diag2_sum != magic_sum) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << magic_sum << std::endl;

    return 0;
}

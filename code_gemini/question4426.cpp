/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "Eh quadrado magico!!!\n";
        return;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    long long target_sum = 0;
    for (int j = 0; j < n; ++j) {
        target_sum += matrix[0][j];
    }

    long long diag1_sum = 0;
    for (int i = 0; i < n; ++i) {
        diag1_sum += matrix[i][i];
    }
    if (diag1_sum != target_sum) {
        std::cout << "Nao eh!!!\n";
        return;
    }

    long long diag2_sum = 0;
    for (int i = 0; i < n; ++i) {
        diag2_sum += matrix[i][n - 1 - i];
    }
    if (diag2_sum != target_sum) {
        std::cout << "Nao eh!!!\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        long long current_row_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_row_sum += matrix[i][j];
        }
        if (current_row_sum != target_sum) {
            std::cout << "Nao eh!!!\n";
            return;
        }
    }

    for (int j = 0; j < n; ++j) {
        long long current_col_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_col_sum += matrix[i][j];
        }
        if (current_col_sum != target_sum) {
            std::cout << "Nao eh!!!\n";
            return;
        }
    }

    std::cout << "Eh quadrado magico!!!\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;
    while (k--) {
        solve();
    }

    return 0;
}

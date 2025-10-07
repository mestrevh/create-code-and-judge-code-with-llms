/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

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

    if (n == m) {
        long long trace = 0;
        long long secondary_diag_sum = 0;
        for (int i = 0; i < n; ++i) {
            trace += matrix[i][i];
            secondary_diag_sum += matrix[i][n - 1 - i];
        }
        std::cout << trace << "\n";
        std::cout << secondary_diag_sum << "\n";
    } else {
        std::cout << "A matriz nao possui traco\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}

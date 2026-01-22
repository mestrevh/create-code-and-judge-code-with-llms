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
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    bool is_permutation = true;

    for (int i = 0; i < n; ++i) {
        int row_sum = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                is_permutation = false;
                break;
            }
            row_sum += matrix[i][j];
        }
        if (!is_permutation || row_sum != 1) {
            is_permutation = false;
            break;
        }
    }

    if (is_permutation) {
        for (int j = 0; j < n; ++j) {
            int col_sum = 0;
            for (int i = 0; i < n; ++i) {
                col_sum += matrix[i][j];
            }
            if (col_sum != 1) {
                is_permutation = false;
                break;
            }
        }
    }

    std::cout << (is_permutation ? "True" : "False") << "\n";

    return 0;
}

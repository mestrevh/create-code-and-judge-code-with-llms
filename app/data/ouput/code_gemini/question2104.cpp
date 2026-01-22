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

    int L;
    std::cin >> L;

    if (L == 0) {
        std::cout << "A matriz e magica" << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> matrix(L, std::vector<int>(L));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    long long magic_sum = 0;
    for (int i = 0; i < L; ++i) {
        magic_sum += matrix[i][i];
    }

    long long anti_diag_sum = 0;
    for (int i = 0; i < L; ++i) {
        anti_diag_sum += matrix[i][L - 1 - i];
    }

    if (anti_diag_sum != magic_sum) {
        std::cout << "A matriz nao e magica" << std::endl;
        return 0;
    }

    for (int i = 0; i < L; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < L; ++j) {
            row_sum += matrix[i][j];
        }
        if (row_sum != magic_sum) {
            std::cout << "A matriz nao e magica" << std::endl;
            return 0;
        }
    }

    for (int j = 0; j < L; ++j) {
        long long col_sum = 0;
        for (int i = 0; i < L; ++i) {
            col_sum += matrix[i][j];
        }
        if (col_sum != magic_sum) {
            std::cout << "A matriz nao e magica" << std::endl;
            return 0;
        }
    }

    std::cout << "A matriz e magica" << std::endl;

    return 0;
}

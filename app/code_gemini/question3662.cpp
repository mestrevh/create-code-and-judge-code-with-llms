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

    int I, J;
    std::cin >> I >> J;

    std::vector<std::vector<int>> matrix(I, std::vector<int>(J));
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < I; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < J; ++j) {
            row_sum += matrix[i][j];
        }
        std::cout << "Linha " << i << ": " << row_sum << "\n";
    }

    for (int j = 0; j < J; ++j) {
        long long col_sum = 0;
        for (int i = 0; i < I; ++i) {
            col_sum += matrix[i][j];
        }
        std::cout << "Coluna " << j << ": " << col_sum << "\n";
    }

    if (I == J) {
        long long diag_sum = 0;
        for (int i = 0; i < I; ++i) {
            diag_sum += matrix[i][i];
        }
        std::cout << "Diagonal principal: " << diag_sum << "\n";
    }

    return 0;
}

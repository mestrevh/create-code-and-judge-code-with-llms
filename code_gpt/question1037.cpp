/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

void gauss(std::vector<std::vector<double>>& matrix, std::vector<double>& result, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= n; ++k) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            result[i] -= matrix[i][j] * result[j];
        }
        result[i] /= matrix[i][i];
    }
}

int main() {
    int n, case_num = 1;
    while (std::cin >> n) {
        std::vector<std::vector<double>> matrix(n, std::vector<double>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        std::vector<double> result(n);
        gauss(matrix, result, n);
        std::cout << "Case #" << case_num++ << ": ";
        for (int i = 0; i < n; ++i) {
            std::cout << std::fixed << std::setprecision(2) << result[i] << (i == n - 1 ? "\n" : " ");
        }
    }
    return 0;
}

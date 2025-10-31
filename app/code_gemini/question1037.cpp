/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int case_num = 1;
    while (std::cin >> n) {
        std::vector<std::vector<double>> mat(n, std::vector<double>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                std::cin >> mat[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            int pivot_row = j;
            for (int i = j + 1; i < n; ++i) {
                if (std::abs(mat[i][j]) > std::abs(mat[pivot_row][j])) {
                    pivot_row = i;
                }
            }

            if (pivot_row != j) {
                std::swap(mat[j], mat[pivot_row]);
            }

            for (int i = j + 1; i < n; ++i) {
                if (mat[j][j] == 0) continue;
                double factor = mat[i][j] / mat[j][j];
                for (int k = j; k < n + 1; ++k) {
                    mat[i][k] -= factor * mat[j][k];
                }
            }
        }

        std::vector<double> solution(n);
        for (int i = n - 1; i >= 0; --i) {
            double sum = 0.0;
            for (int j = i + 1; j < n; ++j) {
                sum += mat[i][j] * solution[j];
            }
            if (mat[i][i] == 0) {
                solution[i] = 0;
            } else {
                solution[i] = (mat[i][n] - sum) / mat[i][i];
            }
        }

        std::cout << "Case #" << case_num++ << ":";
        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < n; ++i) {
            if (std::abs(solution[i]) < 1e-9) {
                solution[i] = 0.0;
            }
            std::cout << " " << solution[i];
        }
        std::cout << std::endl;
    }

    return 0;
}

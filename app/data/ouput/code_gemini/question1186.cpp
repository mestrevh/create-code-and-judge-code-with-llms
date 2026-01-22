/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int rows, cols;
    
    std::cin >> rows;
    std::cin >> cols;

    if (rows <= 0 || cols <= 0 || rows != cols) {
        std::cout << "erro" << std::endl;
        return 0;
    }

    int n = rows;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int overall_max = std::numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] > overall_max) {
                overall_max = matrix[i][j];
            }
        }
    }

    std::cout << "[";
    for (int i = 0; i < n; ++i) {
        int row_max = matrix[i][0];
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] > row_max) {
                row_max = matrix[i][j];
            }
        }
        std::cout << row_max << (i == n - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    std::cout << "[";
    for (int j = 0; j < n; ++j) {
        int col_max = matrix[0][j];
        for (int i = 1; i < n; ++i) {
            if (matrix[i][j] > col_max) {
                col_max = matrix[i][j];
            }
        }
        std::cout << col_max << (j == n - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    std::cout << overall_max << std::endl;

    long long sum_main_diag = 0;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] > 0) {
            sum_main_diag += matrix[i][i];
        }
    }
    std::cout << sum_main_diag << std::endl;

    long long diff_sec_diag = 0;
    if (n > 0) {
        diff_sec_diag = matrix[0][n - 1];
        for (int i = 1; i < n; ++i) {
            diff_sec_diag -= matrix[i][n - 1 - i];
        }
    }
    std::cout << diff_sec_diag << std::endl;

    return 0;
}

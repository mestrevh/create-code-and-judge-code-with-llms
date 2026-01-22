/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void print_matrix(const std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << mat[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

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
        std::sort(matrix[i].begin(), matrix[i].end());
    }

    long long sum_diag = 0;
    for (int i = 0; i < n; ++i) {
        sum_diag += matrix[i][i];
    }

    if (is_prime(sum_diag)) {
        std::cout << "A soma resultou em um numero primo!\n";
        
        std::vector<std::vector<int>> transposed(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (transposed[i][j] % 2 != 0) {
                    transposed[i][j] *= 2;
                }
            }
        }
        print_matrix(transposed);

    } else {
        std::cout << "A soma resultou em um numero nao primo!\n";
        std::cout << sum_diag << "\n";
        
        std::vector<int> diagonal;
        for (int i = 0; i < n; ++i) {
            diagonal.push_back(matrix[i][i]);
        }
        std::sort(diagonal.begin(), diagonal.end());

        for (int i = 0; i < n; ++i) {
            matrix[i][i] = diagonal[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] % 2 != 0) {
                    matrix[i][j] *= 2;
                }
            }
        }
        print_matrix(matrix);
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using matrix = std::vector<std::vector<double>>;

int n;

matrix multiply(const matrix& a, const matrix& b) {
    matrix result(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

matrix matrix_pow(matrix base, long long exp) {
    matrix result(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1.0;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

void print_matrix(const matrix& m) {
    std::cout << std::fixed << std::setprecision(3);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << m[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long k;
    while (std::cin >> n >> k) {
        matrix m(n, std::vector<double>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> m[i][j];
            }
        }

        matrix result = matrix_pow(m, k);
        print_matrix(result);
    }

    return 0;
}

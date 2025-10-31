/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "SIM\n";
        return 0;
    }

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    double max_alpha = 0.0;

    for (int j = 0; j < n; ++j) {
        double sum_off_diagonal = 0.0;
        double diagonal_element = matrix[j][j];

        for (int i = 0; i < n; ++i) {
            if (i != j) {
                sum_off_diagonal += std::fabs(matrix[i][j]);
            }
        }

        if (std::fabs(diagonal_element) == 0) {
            if (sum_off_diagonal > 0) {
                 max_alpha = 2.0;
                 break;
            } else {
                 continue;
            }
        }
        
        double current_alpha = sum_off_diagonal / std::fabs(diagonal_element);
        max_alpha = std::max(max_alpha, current_alpha);
    }

    if (max_alpha < 1.0) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    return 0;
}

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

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    double max_alpha = 0.0;
    bool criteria_met = true;

    for (int i = 0; i < n; ++i) {
        double row_sum = 0.0;
        double diagonal_element = std::fabs(matrix[i][i]);

        if (diagonal_element == 0) {
            criteria_met = false;
            break;
        }

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                row_sum += std::fabs(matrix[i][j]);
            }
        }

        double alpha_i = row_sum / diagonal_element;
        if (alpha_i > max_alpha) {
            max_alpha = alpha_i;
        }
    }

    if (!criteria_met || max_alpha >= 1.0) {
        std::cout << "NAO\n";
    } else {
        std::cout << "SIM\n";
    }

    return 0;
}

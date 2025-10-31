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
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<double> alphas(n);
    double max_alpha = 0.0;

    for (int i = 0; i < n; ++i) {
        double numerator_sum1 = 0.0;
        for (int j = 0; j < i; ++j) {
            numerator_sum1 += std::fabs(matrix[i][j]) * alphas[j];
        }

        double numerator_sum2 = 0.0;
        for (int j = i + 1; j < n; ++j) {
            numerator_sum2 += std::fabs(matrix[i][j]);
        }

        double denominator = std::fabs(matrix[i][i]);
        
        if (denominator != 0) {
            alphas[i] = (numerator_sum1 + numerator_sum2) / denominator;
        } else {
            alphas[i] = 1e18; // A very large number to ensure failure
        }
        
        if (alphas[i] > max_alpha) {
            max_alpha = alphas[i];
        }
    }

    if (max_alpha < 1.0) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; ++i) {
        std::cout << alphas[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}

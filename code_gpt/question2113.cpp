/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> A[i][j];

    std::vector<double> alphas(n);
    bool converges = true;

    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                sum += std::fabs(A[i][j]);
            }
        }
        alphas[i] = sum / std::fabs(A[i][i]);
        if (alphas[i] >= 1.0) {
            converges = false;
        }
    }

    std::cout << (converges ? "SIM" : "NAO") << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << alphas[i];
        if (i < n - 1) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}

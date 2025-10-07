/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> x(n);
    std::vector<double> y(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<std::vector<double>> vandermonde(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vandermonde[i][j] = pow(x[i], j);
        }
    }

    for (const auto& row : vandermonde) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(2) << row[j];
            if (j < n - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

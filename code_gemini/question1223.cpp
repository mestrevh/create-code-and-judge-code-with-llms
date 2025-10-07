/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X, T;
    while (std::cin >> X >> T && (X != 0 || T != 0)) {
        if (T == 0) {
            std::cout << std::fixed << std::setprecision(10) << 0.0 << std::endl;
            continue;
        }

        double x_double = static_cast<double>(X);
        double C = 0.0;
        
        // Termo 1: X
        double term = x_double;
        C += term;

        // Loop para os termos de i=2 até T
        for (int i = 2; i <= T; ++i) {
            if (i == 2) {
                // Razão termo_2 / termo_1 = (-X^2/3!) / X = -X/6
                term *= -x_double / 6.0;
            } else {
                // Razão termo_i / termo_{i-1} = -X^2 / ((2*i-1) * (2*i-2)) para i >= 3
                term *= -(x_double * x_double) / ((2.0 * i - 1.0) * (2.0 * i - 2.0));
            }
            C += term;
        }

        std::cout << std::fixed << std::setprecision(10) << std::abs(C) << std::endl;
    }

    return 0;
}

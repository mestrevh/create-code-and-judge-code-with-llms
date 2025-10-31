/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x;
    int c;
    std::cin >> x >> c;

    if (c == 0) {
        std::cout << std::fixed << std::setprecision(3) << 0.0 << std::endl;
        return 0;
    }

    double v = x;

    if (c > 1) {
        double current_term = -(x * x) / 6.0;
        v += current_term;

        for (int k = 1; k < c - 1; ++k) {
            double multiplier = -(x * x) / ((2.0 * k + 3.0) * (2.0 * k + 2.0));
            current_term *= multiplier;
            v += current_term;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << std::abs(v) << std::endl;

    return 0;
}

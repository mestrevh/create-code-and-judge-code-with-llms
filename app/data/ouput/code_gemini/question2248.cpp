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

    int x_int, t;
    std::cin >> x_int >> t;

    if (t == 0) {
        std::cout << std::fixed << std::setprecision(3) << 0.0 << std::endl;
        return 0;
    }

    double x = static_cast<double>(x_int);
    double v = x;

    if (t > 1) {
        double current_term = -(x * x) / 6.0;
        v += current_term;

        for (int i = 3; i <= t; ++i) {
            double multiplier = -(x * x) / ((2.0 * i - 2.0) * (2.0 * i - 1.0));
            current_term *= multiplier;
            v += current_term;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << std::abs(v) << std::endl;

    return 0;
}

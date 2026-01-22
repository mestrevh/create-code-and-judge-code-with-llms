/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <numeric>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(6);

    // Equation 1
    {
        double sum1 = 0.0;
        double sign = 1.0;
        for (int x = 0; x <= n; ++x) {
            sum1 += sign / (2.0 * x + 1.0);
            sign *= -1.0;
        }
        double pi_approx1 = 4.0 * sum1;
        double percentage1 = pi_approx1 / M_PI;
        std::cout << pi_approx1 << " - " << percentage1 << "\n";
    }

    // Equation 2
    {
        double sum2 = 0.0;
        for (int x = 0; x <= n; ++x) {
            sum2 += 1.0 / ((4.0 * x + 1.0) * (4.0 * x + 3.0));
        }
        double pi_approx2 = 8.0 * sum2;
        double percentage2 = pi_approx2 / M_PI;
        std::cout << pi_approx2 << " - " << percentage2 << "\n";
    }

    // Equation 3
    {
        double pi_approx3 = 3.0;
        double sign = 1.0;
        for (int x = 1; x <= n; ++x) {
            double d = 2.0 * x;
            pi_approx3 += sign * 4.0 / (d * (d + 1.0) * (d + 2.0));
            sign *= -1.0;
        }
        double percentage3 = pi_approx3 / M_PI;
        std::cout << pi_approx3 << " - " << percentage3 << "\n";
    }

    return 0;
}

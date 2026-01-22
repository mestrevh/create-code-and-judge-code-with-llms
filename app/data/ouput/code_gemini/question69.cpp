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

    int n;
    while (std::cin >> n && n != 0) {
        double sum_x = 0.0;
        double sum_y = 0.0;
        double sum_xy = 0.0;
        double sum_x2 = 0.0;
        double sum_y2 = 0.0;

        for (int i = 0; i < n; ++i) {
            double x, y;
            std::cin >> x >> y;
            sum_x += x;
            sum_y += y;
            sum_xy += x * y;
            sum_x2 += x * x;
            sum_y2 += y * y;
        }

        double numerator = n * sum_xy - sum_x * sum_y;
        double den_a = n * sum_x2 - sum_x * sum_x;
        double den_r_term1 = n * sum_x2 - sum_x * sum_x;
        double den_r_term2 = n * sum_y2 - sum_y * sum_y;
        double den_r = std::sqrt(den_r_term1 * den_r_term2);

        double a = 0.0;
        double b = 0.0;
        double r = 0.0;

        if (den_a != 0) {
            a = numerator / den_a;
        }
        b = (sum_y - a * sum_x) / n;

        if (den_r != 0) {
            r = numerator / den_r;
        }

        std::cout << "a = " << std::fixed << std::setprecision(2) << a
                  << ", b = " << b
                  << ", R = " << r << std::endl;
    }

    return 0;
}

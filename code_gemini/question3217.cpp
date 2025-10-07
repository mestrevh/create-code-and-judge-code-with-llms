/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double degrees;
    int n;

    std::cin >> degrees >> n;

    double radians = degrees * M_PI / 180.0;

    double my_sin = 0.0;
    if (n > 0) {
        double term_sin = radians;
        my_sin = term_sin;
        for (int k = 1; k < n; ++k) {
            term_sin = term_sin * (-1.0) * radians * radians / ((2.0 * k) * (2.0 * k + 1.0));
            my_sin += term_sin;
        }
    }

    double my_cos = 0.0;
    if (n > 0) {
        double term_cos = 1.0;
        my_cos = term_cos;
        for (int k = 1; k < n; ++k) {
            term_cos = term_cos * (-1.0) * radians * radians / ((2.0 * k - 1.0) * (2.0 * k));
            my_cos += term_cos;
        }
    }

    std::cout << std::fixed << std::setprecision(5);
    std::cout << my_sin << std::endl;
    std::cout << my_cos << std::endl;

    return 0;
}

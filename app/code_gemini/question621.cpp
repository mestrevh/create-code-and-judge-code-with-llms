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

    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    double a = y1 - y2;
    double b = x2 - x1;
    double c = x1 * y2 - x2 * y1;

    if (std::abs(b) > 1e-9) {
        a /= b;
        c /= b;
        b = 1.0;
    } else {
        c /= a;
        a = 1.0;
        b = 0.0;
    }

    if (std::abs(a) < 1e-9) a = 0.0;
    if (std::abs(b) < 1e-9) b = 0.0;
    if (std::abs(c) < 1e-9) c = 0.0;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "(" << a << "x) + (" << b << "y) + (" << c << ") = 0\n";

    return 0;
}

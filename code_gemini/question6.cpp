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
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "NEESG" << std::endl;
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        std::cout << "NRR" << std::endl;
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << x1 << std::endl;
        std::cout << x2 << std::endl;
    }

    return 0;
}

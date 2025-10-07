/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    double delta = (b * b) - (4 * a * c);

    if (a != 0 && delta >= 0) {
        double x1 = (-b + std::sqrt(delta)) / (2 * a);
        double x2 = (-b - std::sqrt(delta)) / (2 * a);
        
        std::cout << "x1 = " << static_cast<int>(x1) << std::endl;
        std::cout << "x2 = " << static_cast<int>(x2) << std::endl;
    }

    return 0;
}

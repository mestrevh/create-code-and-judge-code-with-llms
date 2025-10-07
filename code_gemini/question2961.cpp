/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double lado;
    std::cin >> lado;

    double area = (3.0 * std::sqrt(3.0) * lado * lado) / 2.0;
    double perimetro = 6.0 * lado;

    std::cout << std::fixed;

    std::cout << "Lado do hexagono: " << std::setprecision(1) << lado << " metros," << std::endl;
    std::cout << "Area: " << std::setprecision(15) << area << " metros quadrados," << std::endl;
    std::cout << "Perimetro: " << std::setprecision(1) << perimetro << " metros." << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double lado;
    std::cout << "Informe a medida de um dos lados do quadrado:" << std::endl;
    std::cin >> lado;
    double area = std::pow(lado, 2);
    double dobro_area = area * 2.0;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Resultado: " << area << std::endl;
    std::cout << "Dobro: " << dobro_area << std::endl;
    return 0;
}

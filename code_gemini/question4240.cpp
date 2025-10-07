/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int angulo1, angulo2;

    std::cout << "Informe o angulo 1" << std::endl;
    std::cin >> angulo1;

    std::cout << "Informe o angulo 2" << std::endl;
    std::cin >> angulo2;

    double angulo3 = 180.0 - angulo1 - angulo2;

    std::cout << "O terceiro angulo = " 
              << std::fixed 
              << std::setprecision(3) 
              << angulo3 
              << std::endl;

    return 0;
}

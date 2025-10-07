/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n_lados;
    double medida_lado;

    std::cout << "Digite o numero de lados:" << std::endl;
    std::cin >> n_lados;
    std::cout << "Digite a medida do lado em cm:" << std::endl;
    std::cin >> medida_lado;

    if (n_lados < 3) {
        std::cout << "NAO E UM POLIGONO" << std::endl;
    } else if (n_lados == 3) {
        double area = (medida_lado * medida_lado * sqrt(3)) / 4.0;
        std::cout << "TRIANGULO" << std::endl;
        std::cout << std::fixed << std::setprecision(4) << "A area do poligono e: " << area << " cm2" << std::endl;
    } else if (n_lados == 4) {
        double area = medida_lado * medida_lado;
        std::cout << "QUADRADO" << std::endl;
        std::cout << std::fixed << std::setprecision(4) << "A area do poligono e: " << area << " cm2" << std::endl;
    } else if (n_lados == 5) {
        std::cout << "PENTAGONO" << std::endl;
    } else {
        std::cout << "POLIGONO NAO IDENTIFICADO" << std::endl;
    }

    return 0;
}

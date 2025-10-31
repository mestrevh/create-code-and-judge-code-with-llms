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

    int lados;
    double medida;

    std::cin >> lados >> medida;

    std::cout << "Digite o numero de lados:" << std::endl;
    std::cout << "Digite a medida do lado em cm:" << std::endl;

    if (lados < 3) {
        std::cout << "NAO E UM POLIGONO" << std::endl;
    } else if (lados == 3) {
        std::cout << "TRIANGULO" << std::endl;
        double area = (medida * medida * std::sqrt(3.0)) / 4.0;
        std::cout << std::fixed << std::setprecision(4) << "A area do poligono e: " << area << " cm2" << std::endl;
    } else if (lados == 4) {
        std::cout << "QUADRADO" << std::endl;
        double area = medida * medida;
        std::cout << "A area do poligono e: " << area << " cm2" << std::endl;
    } else if (lados == 5) {
        std::cout << "PENTAGONO" << std::endl;
    } else {
        std::cout << "POLIGONO NAO IDENTIFICADO" << std::endl;
    }

    return 0;
}

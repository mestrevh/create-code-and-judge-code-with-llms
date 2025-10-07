/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double A, B, C;
    std::cout << "Digite o coeficiente A:\n";
    std::cin >> A;
    std::cout << "Digite o coeficiente B:\n";
    std::cin >> B;
    std::cout << "Digite o coeficiente C:\n";
    std::cin >> C;

    double delta = B * B - 4 * A * C;

    if (delta < 0) {
        std::cout << "A funcao nao tem raizes reais\n";
    } else {
        double raiz1 = (-B + sqrt(delta)) / (2 * A);
        double raiz2 = (-B - sqrt(delta)) / (2 * A);
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Primeira raiz: " << raiz1 << "\n";
        std::cout << "Segunda raiz: " << raiz2 << "\n";
    }

    return 0;
}

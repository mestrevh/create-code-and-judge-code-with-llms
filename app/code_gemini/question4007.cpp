/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c;

    std::cout << "Digite o coeficiente A:" << std::endl;
    std::cout << "Digite o coeficiente B:" << std::endl;
    std::cout << "Digite o coeficiente C:" << std::endl;

    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "A funcao nao tem raizes reais" << std::endl;
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        std::cout << "A funcao nao tem raizes reais" << std::endl;
    } else {
        double r1 = (-b + std::sqrt(delta)) / (2 * a);
        double r2 = (-b - std::sqrt(delta)) / (2 * a);
        
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Primeira raiz: " << r1 << std::endl;
        std::cout << "Segunda raiz: " << r2 << std::endl;
    }

    return 0;
}

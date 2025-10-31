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

    std::cout << "Digite o coeficiente A:" << '\n';
    std::cout << "Digite o coeficiente B:" << '\n';
    std::cout << "Digite o coeficiente C:" << '\n';

    if (a == 0) {
        std::cout << "A funcao nao tem raizes reais" << '\n';
        return 0;
    }

    double delta = (b * b) - (4 * a * c);

    if (delta < 0) {
        std::cout << "A funcao nao tem raizes reais" << '\n';
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);

        std::cout << "Primeira raiz: " << x1 << '\n';
        std::cout << "Segunda raiz: " << x2 << '\n';
    }

    return 0;
}

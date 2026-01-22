/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double cateto1, cateto2;
    std::cout << "Digite o valor do primeiro cateto:\n";
    std::cin >> cateto1;
    std::cout << "Digite o valor do segundo cateto:\n";
    std::cin >> cateto2;

    if (cateto1 <= 0 || cateto2 <= 0) {
        std::cout << "Valor de cateto invalido.\n";
    } else {
        double hipotenusa = std::sqrt(cateto1 * cateto1 + cateto2 * cateto2);
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "O triangulo cujos catetos sao " << cateto1 << " e " << cateto2 << " tem hipotenusa " << hipotenusa << ".\n";
    }

    return 0;
}

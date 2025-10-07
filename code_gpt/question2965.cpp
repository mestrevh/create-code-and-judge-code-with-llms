/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double area;
    std::cin >> area;

    double litrosNecessarios = area / 7.0;

    int latas24 = std::ceil(litrosNecessarios / 24);
    double preco24 = latas24 * 91.0;

    int latas54 = std::ceil(litrosNecessarios / 5.4);
    double preco54 = latas54 * 23.0;

    int latas24c = litrosNecessarios / 24;
    double litrosRestantes = litrosNecessarios - (latas24c * 24);
    int latas54c = std::ceil(litrosRestantes / 5.4);
    double precoTotal = (latas24c * 91.0) + (latas54c * 23.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "a) " << latas24 << " lata(s) de 24 litros: R$ " << preco24 << std::endl;
    std::cout << "b) " << latas54 << " lata(s) de 5.4 litros: R$ " << preco54 << std::endl;
    std::cout << "c) " << latas24c << " lata(s) de 24 litros e " << latas54c << " lata(s) de 5.4 litros: R$ " << precoTotal << std::endl;

    return 0;
}

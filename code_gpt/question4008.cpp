/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valorReais;
    const double cotacaoDolar = 3.87;
    const double cotacaoEuro = 4.35;

    while (std::cin >> valorReais) {
        std::cout << "Digite o valor em reais:" << std::endl;
        std::cout << "Valor convertido em dolar: " << std::fixed << std::setprecision(2) << (valorReais / cotacaoDolar) << std::endl;
        std::cout << "Valor convertido em euro: " << std::fixed << std::setprecision(2) << (valorReais / cotacaoEuro) << std::endl;
    }

    return 0;
}

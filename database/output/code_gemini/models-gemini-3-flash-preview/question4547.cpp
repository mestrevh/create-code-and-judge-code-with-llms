/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double kwh;
    if (!(std::cin >> kwh)) return 0;

    double valorConsumo = kwh * 0.75;
    double valorTaxa = valorConsumo * 0.05;
    double valorTotal = valorConsumo + valorTaxa;

    std::cout << "Valor do consumo: R$ " << valorConsumo << "\n";
    std::cout << "Valor taxa iluminacao: R$ " << valorTaxa << "\n";
    std::cout << "Valor total a pagar: R$ " << valorTotal << std::endl;

    return 0;
}
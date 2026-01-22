/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int veiculos, casasMultadas = 0;
    double totalArrecadado = 0.0;
    const double multaPorVeiculoExtra = 12.89;

    while (true) {
        std::cin >> veiculos;
        if (veiculos == 999) break;
        if (veiculos > 2) {
            casasMultadas++;
            totalArrecadado += (veiculos - 2) * multaPorVeiculoExtra;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << totalArrecadado << std::endl;
    std::cout << casasMultadas << std::endl;

    return 0;
}

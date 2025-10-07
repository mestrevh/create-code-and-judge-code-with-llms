/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int veiculos;
    int casas_multadas = 0;
    double total_arrecadado = 0.0;
    const double valor_multa = 12.89;

    while (std::cin >> veiculos && veiculos != 999) {
        if (veiculos > 2) {
            int veiculos_extras = veiculos - 2;
            total_arrecadado += veiculos_extras * valor_multa;
            casas_multadas++;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total_arrecadado << std::endl;
    std::cout << casas_multadas << std::endl;

    return 0;
}

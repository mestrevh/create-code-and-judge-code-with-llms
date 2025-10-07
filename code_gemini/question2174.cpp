/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double consumo_m3, custo_litro;
    std::cin >> consumo_m3 >> custo_litro;

    double valor_agua = consumo_m3 * 1000.0 * custo_litro;
    double valor_esgoto = valor_agua * 0.80;
    double valor_total = valor_agua + valor_esgoto;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << valor_agua << std::endl;
    std::cout << valor_esgoto << std::endl;
    std::cout << valor_total << std::endl;

    return 0;
}

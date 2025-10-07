/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int consumo;
    std::cin >> consumo;

    double valor_kwh = 0.0;
    double valor_conta = 0.0;

    if (consumo <= 99) {
        valor_kwh = 1.35;
    } else if (consumo <= 299) {
        valor_kwh = 1.55;
    } else if (consumo <= 574) {
        valor_kwh = 1.75;
    } else {
        valor_kwh = 2.15;
    }

    valor_conta = consumo * valor_kwh;

    if (consumo > 300) {
        valor_conta *= 1.10;
    }

    if (valor_conta < 35.00) {
        valor_conta = 35.00;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << valor_conta << std::endl;
    std::cout << valor_kwh << std::endl;

    return 0;
}

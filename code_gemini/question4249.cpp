/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double kwh_consumido;
    const double custo_kwh = 1.50;
    const double percentual_desconto = 0.85;

    std::cout << "Digite o valor real em KWh consumido:\n";
    std::cin >> kwh_consumido;

    double valor_total = kwh_consumido * custo_kwh;
    double valor_com_desconto = valor_total * percentual_desconto;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor a ser pago: R$ " << valor_total << " reais\n";
    std::cout << "Valor a ser pago com desconto: R$ " << valor_com_desconto << " reais\n";

    return 0;
}

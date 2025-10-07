/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double kWh;
    std::cout << "Digite o valor real em KWh consumido:\n";
    std::cin >> kWh;

    double valorPago = kWh * 1.50;
    double valorComDesconto = valorPago * 0.85;

    std::cout << "Valor a ser pago: R$ " << std::fixed << std::setprecision(2) << valorPago << " reais\n";
    std::cout << "Valor a ser pago com desconto: R$ " << valorComDesconto << " reais\n";

    return 0;
}

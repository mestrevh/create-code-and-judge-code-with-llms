/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valorCompra, valorVenda;

    std::cout << "Digite o valor de compra do produto:\n";
    std::cin >> valorCompra;

    if (valorCompra < 20.0) {
        valorVenda = valorCompra * 1.45;
    } else {
        valorVenda = valorCompra * 1.30;
    }

    std::cout << "O produto deve ser vendido a R$ " << std::fixed << std::setprecision(2) << valorVenda << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor_compra;

    std::cout << "Digite o valor de compra do produto:" << std::endl;
    std::cin >> valor_compra;

    double valor_venda;
    if (valor_compra < 20.00) {
        valor_venda = valor_compra * 1.45;
    } else {
        valor_venda = valor_compra * 1.30;
    }

    std::cout << "O produto deve ser vendido a R$ " << std::fixed << std::setprecision(2) << valor_venda << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor_compra;
    double valor_venda;

    std::cout << "Digite o valor de compra do produto:" << std::endl;
    std::cin >> valor_compra;

    if (valor_compra < 20.0) {
        valor_venda = valor_compra * 1.45;
    } else {
        valor_venda = valor_compra * 1.30;
    }

    std::cout << "O produto deve ser vendido a R$ " << valor_venda << std::endl;

    return 0;
}

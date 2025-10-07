/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double compra, venda;
    std::cout << "Digite o valor de compra do produto:\n";
    std::cin >> compra;

    if (compra < 20.0) {
        venda = compra * 1.45;
    } else {
        venda = compra * 1.30;
    }

    std::cout << "O produto deve ser vendido a R$ " << std::fixed << std::setprecision(2) << venda << std::endl;
    return 0;
}

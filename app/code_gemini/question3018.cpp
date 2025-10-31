/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double preco_litro, valor_pagamento;
    std::cin >> preco_litro >> valor_pagamento;
    double litros = valor_pagamento / preco_litro;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Você conseguiu colocar " << litros << " litros!" << std::endl;
    return 0;
}

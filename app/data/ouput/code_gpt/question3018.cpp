/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double precoLitro, valorPagamento;
    while (std::cin >> precoLitro >> valorPagamento) {
        double litros = valorPagamento / precoLitro;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Voce conseguiu colocar " << litros << " litros!" << std::endl;
    }
    return 0;
}

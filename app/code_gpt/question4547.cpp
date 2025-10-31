/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double consumo;
    std::cin >> consumo;
    
    double valorConsumo = consumo * 0.75;
    double taxaIluminacao = valorConsumo * 0.05;
    double valorTotal = valorConsumo + taxaIluminacao;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor do consumo: R$ " << valorConsumo << std::endl;
    std::cout << "Valor taxa iluminacao: R$ " << taxaIluminacao << std::endl;
    std::cout << "Valor total a pagar: R$ " << valorTotal << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double consumo;
    std::cin >> consumo;
    double valor_consumo = consumo * 0.75;
    double taxa_iluminacao = valor_consumo * 0.05;
    double valor_total = valor_consumo + taxa_iluminacao;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Valor do consumo: R$ " << valor_consumo << std::endl;
    std::cout << "Valor taxa iluminacao: R$ " << taxa_iluminacao << std::endl;
    std::cout << "Valor total a pagar: R$ " << valor_total << std::endl;
    return 0;
}


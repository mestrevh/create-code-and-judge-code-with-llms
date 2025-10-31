/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double consumo_kwh;
    std::cin >> consumo_kwh;

    double valor_consumo = consumo_kwh * 0.75;
    double valor_taxa_iluminacao = valor_consumo * 0.05;
    double valor_total = valor_consumo + valor_taxa_iluminacao;

    std::cout << "Valor do consumo: R$ " << valor_consumo << std::endl;
    std::cout << "Valor taxa iluminacao: R$ " << valor_taxa_iluminacao << std::endl;
    std::cout << "Valor total a pagar: R$ " << valor_total << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double preco_avela, preco_caramelo, preco_passas;
    int qtd_avela, qtd_caramelo, qtd_passas;

    std::cin >> preco_avela;
    std::cin >> preco_caramelo;
    std::cin >> preco_passas;

    std::cin >> qtd_avela;
    std::cin >> qtd_caramelo;
    std::cin >> qtd_passas;

    double total = (preco_avela * qtd_avela) + (preco_caramelo * qtd_caramelo) + (preco_passas * qtd_passas);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor: R$" << total << std::endl;

    return 0;
}

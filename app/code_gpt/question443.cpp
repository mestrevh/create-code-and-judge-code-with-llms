/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int escoteiros;
    std::cin >> escoteiros;

    double preco_pao = 4.15 / 23; // Preço por fatia de pão
    double preco_queijo = 3.89 / 8; // Preço por fatia de queijo

    double custo_sanduiche = (2 * preco_pao + preco_queijo); // Custo por sanduíche
    double total = escoteiros * custo_sanduiche; // Custo total

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}

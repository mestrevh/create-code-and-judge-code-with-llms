/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int jogos_vendidos;
    std::cin >> jogos_vendidos;

    const double PRECO_JOGO = 19.90;
    const double PERCENTUAL_SALARIO = 0.50;
    const double PERCENTUAL_BONUS = 0.08;
    const int JOGOS_PARA_BONUS = 15;

    double total_vendas = jogos_vendidos * PRECO_JOGO;
    int numero_de_bonus = jogos_vendidos / JOGOS_PARA_BONUS;
    double valor_bonus = numero_de_bonus * (total_vendas * PERCENTUAL_BONUS);
    double salario_final = (total_vendas * PERCENTUAL_SALARIO) + valor_bonus;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total_vendas << std::endl;
    std::cout << valor_bonus << std::endl;
    std::cout << salario_final << std::endl;

    return 0;
}

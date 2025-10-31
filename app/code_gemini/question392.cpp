/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int duracao_ligacao;
    int minutos_totais = 0;
    int numero_ligacoes = 0;

    while (std::cin >> duracao_ligacao && duracao_ligacao != 0) {
        minutos_totais += duracao_ligacao;
        numero_ligacoes++;
    }

    double valor_a_pagar = 10.00;

    if (minutos_totais > 40) {
        int minutos_excedentes = minutos_totais - 40;
        valor_a_pagar += minutos_excedentes * 0.20;
    }

    std::cout << std::fixed << std::setprecision(2) << valor_a_pagar << std::endl;

    return 0;
}

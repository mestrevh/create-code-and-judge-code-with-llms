/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double valor_total_troca = 0.0;
    int itens_trocados = 0;

    for (int i = 0; i < 6; ++i) {
        double valor_presente;
        int quantidade;
        std::cin >> valor_presente >> quantidade;

        if (quantidade > 1) {
            int quantidade_para_troca = quantidade - 1;
            itens_trocados += quantidade_para_troca;
            valor_total_troca += quantidade_para_troca * valor_presente;
        }
    }

    std::cout << itens_trocados << std::endl;

    if (valor_total_troca >= 800) {
        std::cout << "SIM" << std::endl;
    } else {
        std::cout << "NAO" << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double valor_arvore;
    std::cin >> valor_arvore;

    double total_enfeites = 0.0;
    for (int i = 0; i < 3; ++i) {
        int quantidade;
        double valor_unitario;
        std::cin >> quantidade;
        std::cin >> valor_unitario;
        total_enfeites += quantidade * valor_unitario;
    }

    double total_gasto = valor_arvore + total_enfeites;
    double valor_por_pessoa = total_gasto / 21.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total_gasto << std::endl;
    std::cout << valor_por_pessoa << std::endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double arvore, total_enfeites = 0;
    int quantidade;
    double preco;
    
    std::cin >> arvore;
    
    for (int i = 0; i < 3; ++i) {
        std::cin >> quantidade >> preco;
        total_enfeites += quantidade * preco;
    }
    
    double total_gasto = arvore + total_enfeites;
    double valor_por_funcionario = total_gasto / 20;
    
    std::cout << std::fixed << std::setprecision(2) << total_gasto << std::endl;
    std::cout << valor_por_funcionario << std::endl;
    
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n_escoteiros;
    std::cin >> n_escoteiros;
    
    double preco_pao_unidade = 4.15 / 23.0;
    double preco_queijo_unidade = 3.89 / 8.0;
    
    int fatias_pao_total = n_escoteiros * 2;
    int fatias_queijo_total = n_escoteiros;
    
    double custo_total = (fatias_pao_total * preco_pao_unidade) + (fatias_queijo_total * preco_queijo_unidade);
    
    std::cout << std::fixed << std::setprecision(2) << custo_total << std::endl;
    
    return 0;
}

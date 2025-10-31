/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double custo_espetaculo;
    double preco_convite;
    
    std::cin >> custo_espetaculo;
    std::cin >> preco_convite;
    
    int convites_para_custo = static_cast<int>(ceil(custo_espetaculo / preco_convite));
    
    double custo_com_lucro = custo_espetaculo * 1.23;
    int convites_para_lucro = static_cast<int>(ceil(custo_com_lucro / preco_convite));
    
    std::cout << convites_para_custo << std::endl;
    std::cout << convites_para_lucro << std::endl;
    
    return 0;
}

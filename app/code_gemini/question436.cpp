/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int mulheres, homens;
    std::cin >> mulheres >> homens;
    
    double custo_total = (mulheres * 10.0) + (homens * 8.50);
    int total_funcionarios = mulheres + homens;
    
    double custo_medio = 0.0;
    if (total_funcionarios > 0) {
        custo_medio = custo_total / total_funcionarios;
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << custo_total << std::endl;
    std::cout << custo_medio << std::endl;
    
    return 0;
}

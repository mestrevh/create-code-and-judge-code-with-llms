/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int laranjas;
    std::cin >> laranjas;
    
    int duzias = laranjas / 12;
    double custo_total = laranjas * (8.35 / 12.0);
    
    std::cout << duzias << std::endl;
    std::cout << std::fixed << std::setprecision(2) << custo_total << std::endl;
    
    return 0;
}

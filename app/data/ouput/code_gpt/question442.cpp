/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int laranjas;
    std::cin >> laranjas;
    
    int duzias = laranjas / 12;
    double custo = duzias * 8.35 + (laranjas % 12) * (8.35 / 12);
    
    std::cout << duzias << std::endl;
    std::cout << std::fixed << std::setprecision(2) << custo << std::endl;
    
    return 0;
}

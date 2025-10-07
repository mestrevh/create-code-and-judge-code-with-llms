/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int QUANTL, QUANTF, TAMEQ, NUMB;
    std::cin >> QUANTL >> QUANTF >> TAMEQ >> NUMB;
    
    float eficiencia = (static_cast<float>(QUANTL) / QUANTF) / TAMEQ - 4.2f * NUMB;
    
    std::cout << std::fixed << std::setprecision(1) << eficiencia << std::endl;
    
    return 0;
}

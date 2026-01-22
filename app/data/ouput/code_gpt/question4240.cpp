/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int angulo1, angulo2;
    std::cout << "Informe o angulo 1\n";
    std::cin >> angulo1;
    std::cout << "Informe o angulo 2\n";
    std::cin >> angulo2;
    
    double terceiroAngulo = 180 - (angulo1 + angulo2);
    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "O terceiro angulo = " << terceiroAngulo << std::endl;
    
    return 0;
}

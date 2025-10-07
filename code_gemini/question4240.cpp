/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int angulo1, angulo2;
    
    std::cout << "Informe o angulo 1 " << std::endl;
    std::cin >> angulo1;
    
    std::cout << "Informe o angulo 2 " << std::endl;
    std::cin >> angulo2;
    
    double angulo3 = 180.0 - angulo1 - angulo2;
    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "O terceiro angulo = " << angulo3 << std::endl;
    
    return 0;
}

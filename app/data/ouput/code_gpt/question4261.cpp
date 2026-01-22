/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    float baseMaior, baseMenor, altura;
    
    std::cout << "Digite o valor da base maior: ";
    std::cin >> baseMaior;
    
    std::cout << "Digite o valor da base menor: ";
    std::cin >> baseMenor;
    
    std::cout << "Digite o valor da altura: ";
    std::cin >> altura;
    
    float area = ((baseMaior + baseMenor) * altura) / 2;
    std::cout << "A parte inteira da área equivale a: " << static_cast<int>(area) << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double baseMaior, baseMenor, altura;

    std::cout << "Digite o valor da base maior: " << std::endl;
    std::cin >> baseMaior;

    std::cout << "Digite o valor da base menor: " << std::endl;
    std::cin >> baseMenor;

    std::cout << "Digite o valor da altura: " << std::endl;
    std::cin >> altura;

    double area = ((baseMaior + baseMenor) * altura) / 2.0;
    int parteInteira = static_cast<int>(area);

    std::cout << "A parte inteira da área equivale a: " << parteInteira << std::endl;

    return 0;
}

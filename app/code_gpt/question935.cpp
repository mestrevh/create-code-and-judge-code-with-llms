/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double nota1, nota2, nota3, media;
    std::cout << "Informe a primeira nota:\n";
    std::cin >> nota1;
    std::cout << "Informe a segunda nota:\n";
    std::cin >> nota2;
    std::cout << "Informe a terceira nota:\n";
    std::cin >> nota3;
    
    media = (nota1 + nota2 + nota3) / 3.0;
    
    std::cout << std::fixed << std::setprecision(1);
    if (media >= 7.0) {
        std::cout << "Aprovado com media " << media << std::endl;
    } else if (media >= 5.0) {
        std::cout << "Recuperacao com media " << media << std::endl;
    } else {
        std::cout << "Reprovado com media " << media << std::endl;
    }
    
    return 0;
}

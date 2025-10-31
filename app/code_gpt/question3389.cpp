/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    double preco;
    char categoria;
    
    std::cin >> preco >> categoria;
    
    std::cout << std::fixed << std::setprecision(2);
    
    if (categoria == 'E' || categoria == 'e') {
        std::cout << "Preco com desconto: R$" << preco * 0.5 << "\n";
        std::cout << "Categoria: Estudante" << std::endl;
    } else if (categoria == 'A' || categoria == 'a') {
        std::cout << "Preco com desconto: R$" << preco * 0.7 << "\n";
        std::cout << "Categoria: Aposentado" << std::endl;
    } else if (categoria == 'N' || categoria == 'n') {
        std::cout << "Preco sem desconto: R$" << preco << "\n";
    } else {
        std::cout << "Categoria invalida!" << std::endl;
    }
    
    return 0;
}

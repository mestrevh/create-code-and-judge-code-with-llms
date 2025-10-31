/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double preco;
    char categoria;

    std::cin >> preco >> categoria;

    categoria = std::toupper(categoria);

    std::cout << std::fixed << std::setprecision(2);

    switch (categoria) {
        case 'E':
            std::cout << "Preco com desconto: R$" << preco * 0.50 << std::endl;
            std::cout << "Categoria: Estudante" << std::endl;
            break;
        case 'A':
            std::cout << "Preco com desconto: R$" << preco * 0.70 << std::endl;
            std::cout << "Categoria: Aposentado" << std::endl;
            break;
        case 'N':
            std::cout << "Preco sem desconto: R$" << preco << std::endl;
            break;
        default:
            std::cout << "Categoria invalida!" << std::endl;
            break;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double largura, comprimento, altura;
    std::cin >> largura >> comprimento >> altura;
    if (largura <= 45 && comprimento <= 56 && altura <= 25) {
        std::cout << "PERMITIDA" << std::endl;
    } else {
        std::cout << "PROIBIDA" << std::endl;
    }
    return 0;
}

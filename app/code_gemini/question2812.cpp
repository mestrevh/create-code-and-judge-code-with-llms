/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double largura, comprimento, altura;

    std::cout << "Digite a largura da bagagem:" << std::endl;
    std::cin >> largura;

    std::cout << "Digite o comprimento da bagagem:" << std::endl;
    std::cin >> comprimento;

    std::cout << "Digite a altura da bagagem:" << std::endl;
    std::cin >> altura;

    if (largura <= 45 && comprimento <= 56 && altura <= 25) {
        std::cout << "BAGAGEM PERMITIDA" << std::endl;
    } else {
        std::cout << "BAGAGEM PROIBIDA" << std::endl;
    }

    return 0;
}

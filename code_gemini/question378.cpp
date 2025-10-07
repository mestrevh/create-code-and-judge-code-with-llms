/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int soma = 0;
    int pontos;
    for (int i = 0; i < 6; ++i) {
        std::cin >> pontos;
        soma += pontos;
    }
    if (soma >= 100) {
        std::cout << "Classificado" << std::endl;
    } else {
        std::cout << "Eliminado" << std::endl;
    }
    return 0;
}

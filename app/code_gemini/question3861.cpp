/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade;
    while (std::cin >> idade && idade != 0) {
        if (idade < 0) {
            std::cout << "Voce ainda nao nasceu.\n";
        } else if (idade >= 1 && idade <= 11) {
            std::cout << "Você é uma criança.\n";
        } else if (idade >= 12 && idade <= 17) {
            std::cout << "Você é um adolescente.\n";
        } else if (idade >= 18 && idade <= 35) {
            std::cout << "Você é um jovem.\n";
        } else if (idade >= 36 && idade <= 64) {
            std::cout << "Você é um adulto.\n";
        } else {
            std::cout << "Você é um idoso.\n";
        }
    }
    return 0;
}

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
            std::cout << "Você ainda não nasceu.\n";
        } else if (idade < 16) {
            std::cout << "Você não pode votar.\n";
        } else if (idade >= 18 && idade <= 70) {
            std::cout << "Você tem a obrigatoriedade de votar.\n";
        } else {
            std::cout << "Na sua idade, o voto é opcional.\n";
        }
    }
    return 0;
}

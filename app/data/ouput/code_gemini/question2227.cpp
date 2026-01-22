/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string direita, meio, esquerda;
    std::cin >> direita >> meio >> esquerda;

    if (!direita.empty() && tolower(direita.front()) == 'f' && tolower(direita.back()) == 'r') {
        std::cout << "Direita" << std::endl;
    } else if (!meio.empty() && tolower(meio.front()) == 'f' && tolower(meio.back()) == 'r') {
        std::cout << "Meio" << std::endl;
    } else if (!esquerda.empty() && tolower(esquerda.front()) == 'f' && tolower(esquerda.back()) == 'r') {
        std::cout << "Esquerda" << std::endl;
    } else {
        std::cout << "Vou em frente" << std::endl;
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int contar_palavras_na_frase(const std::string& palavra, const std::string& frase) {
    std::istringstream iss(frase);
    std::string palavra_atual;
    int contador = 0;

    while (iss >> palavra_atual) {
        if (palavra_atual == palavra) {
            contador++;
        }
    }

    return contador;
}

int main() {
    std::string palavra, frase;
    std::getline(std::cin, palavra);
    std::getline(std::cin, frase);

    std::cout << contar_palavras_na_frase(palavra, frase) << std::endl;
    return 0;
}

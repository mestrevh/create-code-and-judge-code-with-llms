/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

std::string criptografar(const std::string& frase) {
    std::string resultado;
    for (char c : frase) {
        if (std::isalpha(c) && std::islower(c)) {
            resultado += 'z' - (c - 'a');
        } else {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    std::string entrada;
    std::getline(std::cin, entrada);
    std::cout << criptografar(entrada) << std::endl;
    return 0;
}

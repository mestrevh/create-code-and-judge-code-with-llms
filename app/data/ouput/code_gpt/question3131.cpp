/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

std::string remover_especiais(const std::string &palavra) {
    std::string resultado;
    for (char c : palavra) {
        if (isalpha(c)) {
            resultado += tolower(c);
        }
    }
    return resultado;
}

int main() {
    std::set<std::string> palavras;
    std::string linha;

    while (std::getline(std::cin, linha) && linha != "-1") {
        std::istringstream iss(linha);
        std::string palavra;
        while (iss >> palavra) {
            std::string palavra_limpa = remover_especiais(palavra);
            if (!palavra_limpa.empty()) {
                palavras.insert(palavra_limpa);
            }
        }
    }

    for (const auto &palavra : palavras) {
        std::cout << palavra << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string referencia(const std::string& nome) {
    std::stringstream ss(nome);
    std::string palavra;
    std::vector<std::string> palavras;
    std::string resultado;

    while (ss >> palavra) {
        palavras.push_back(palavra);
    }

    if (palavras.empty()) {
        return "";
    }

    std::string sobrenome = palavras.back();
    std::transform(sobrenome.begin(), sobrenome.end(), sobrenome.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    resultado += sobrenome;
    resultado += ", ";

    for (size_t i = 0; i < palavras.size() - 1; ++i) {
        resultado += palavras[i];
        if (i < palavras.size() - 2) {
            resultado += " ";
        }
    }

    resultado += ".";

    return resultado;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string nomeCompleto;
    std::getline(std::cin, nomeCompleto);
    std::cout << referencia(nomeCompleto) << std::endl;
    return 0;
}

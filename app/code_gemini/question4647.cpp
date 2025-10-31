/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string palavra;
    std::getline(std::cin, palavra);

    std::string frase;
    std::getline(std::cin, frase);

    std::transform(palavra.begin(), palavra.end(), palavra.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    std::transform(frase.begin(), frase.end(), frase.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (frase.find(palavra) != std::string::npos) {
        std::cout << "existe!" << std::endl;
    } else {
        std::cout << "nao existe" << std::endl;
    }

    return 0;
}

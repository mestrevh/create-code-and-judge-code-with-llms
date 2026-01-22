/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int contar_vogais(const std::string& vogais, const std::string& frase) {
    int contagem = 0;
    for (char c : frase) {
        if (vogais.find(c) != std::string::npos) {
            contagem++;
        }
    }
    return contagem;
}

int main() {
    int casos;
    std::cin >> casos;
    std::cin.ignore();
    for (int i = 0; i < casos; i++) {
        std::string vogais, frase;
        std::getline(std::cin, vogais);
        std::getline(std::cin, frase);
        std::cout << contar_vogais(vogais, frase) << std::endl;
    }
    return 0;
}

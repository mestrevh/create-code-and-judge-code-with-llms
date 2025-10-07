/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    char letra;
    std::string frase;
    std::cin >> letra >> std::getline(std::cin >> std::ws, frase);
    int posicao = -1;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == letra) {
            posicao = i + 1;
            break;
        }
    }
    if (posicao != -1) {
        std::cout << posicao << std::endl;
    } else {
        std::cout << "a frase nao possui a letra" << std::endl;
    }
    return 0;
}


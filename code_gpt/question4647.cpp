/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string palavra, frase;
    std::getline(std::cin, palavra);
    std::getline(std::cin, frase);
    
    if (frase.find(palavra) != std::string::npos) {
        std::cout << "existe!" << std::endl;
    } else {
        std::cout << "nao existe" << std::endl;
    }
    
    return 0;
}

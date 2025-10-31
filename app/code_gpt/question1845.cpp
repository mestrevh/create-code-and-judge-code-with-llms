/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string nome;
    std::getline(std::cin, nome);
    
    std::string nomeInvertido;
    for (int i = nome.length() - 1; i >= 0; --i) {
        nomeInvertido += nome[i];
    }
    
    if (!nomeInvertido.empty()) {
        nomeInvertido[0] = toupper(nomeInvertido[0]);
        nomeInvertido[nomeInvertido.length() - 1] = toupper(nomeInvertido[nomeInvertido.length() - 1]);
    }
    
    std::cout << nomeInvertido << std::endl;
    
    return 0;
}

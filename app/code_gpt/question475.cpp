/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> nomes(10);
    char letra;
    
    for (int i = 0; i < 10; ++i) {
        std::getline(std::cin, nomes[i]);
    }
    
    std::cin >> letra;
    letra = tolower(letra);
    
    for (const auto& nome : nomes) {
        if (std::find_if(nome.begin(), nome.end(), [letra](char c) { return tolower(c) == letra; }) != nome.end()) {
            std::cout << nome << std::endl;
        }
    }
    
    return 0;
}

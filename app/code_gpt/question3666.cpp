/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> convidados;
    std::string nome;
    
    while (std::getline(std::cin, nome) && nome != "FIM") {
        convidados.push_back(nome);
    }

    std::sort(convidados.begin(), convidados.end());
    
    for (const auto& convidado : convidados) {
        std::cout << convidado << std::endl;
    }

    int n;
    while (std::cin >> n && n != 0) {
        std::cin.ignore();
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, nome);
            convidados.push_back(nome);
        }
        std::sort(convidados.begin(), convidados.end());
        
        std::cout << "--------------------------------------------------" << std::endl;
        
        for (const auto& convidado : convidados) {
            std::cout << convidado << std::endl;
        }
    }

    return 0;
}

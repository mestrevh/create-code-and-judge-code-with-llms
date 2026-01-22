/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> marilda, irmao;
    std::string nome;

    while (std::getline(std::cin, nome) && nome != "FIM") {
        marilda.push_back(nome);
    }

    while (std::getline(std::cin, nome) && nome != "FIM") {
        irmao.push_back(nome);
    }

    std::sort(marilda.begin(), marilda.end());
    std::sort(irmao.begin(), irmao.end());

    for (const auto& convidado : marilda) {
        std::cout << convidado << std::endl;
    }
    
    std::cout << "--------------------------------------------------" << std::endl;

    for (const auto& convidado : irmao) {
        std::cout << convidado << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;

    std::vector<std::string> todos_convidados = marilda;
    todos_convidados.insert(todos_convidados.end(), irmao.begin(), irmao.end());
    std::sort(todos_convidados.begin(), todos_convidados.end());

    for (const auto& convidado : todos_convidados) {
        std::cout << convidado << std::endl;
    }

    return 0;
}

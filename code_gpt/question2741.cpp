/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> pessoas;
    std::string comando, nome;

    while (std::getline(std::cin, comando)) {
        if (comando.substr(0, 7) == "INSERIR") {
            nome = comando.substr(8);
            pessoas.insert(nome);
        } else if (comando.substr(0, 7) == "REMOVER") {
            nome = comando.substr(8);
            pessoas.erase(nome);
        } else if (comando == "IMPRIMIR") {
            std::cout << "Atualmente trabalhando:\n";
            for (const auto& p : pessoas) {
                std::cout << p << "\n";
            }
            std::cout << "\n";
        }
    }
    return 0;
}

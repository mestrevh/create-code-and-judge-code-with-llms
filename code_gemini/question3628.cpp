/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Cliente {
    std::string nome;
    int senha;
    char situacao;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Cliente> clientes;

    for (int i = 0; i < 100; ++i) {
        std::string nome;
        std::getline(std::cin, nome);

        if (nome == "SAIR") {
            break;
        }

        int senha;
        char situacao;
        
        std::cin >> senha;
        std::cin >> situacao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clientes.push_back({nome, senha, situacao});
    }

    int senha_tentativa;
    while (std::cin >> senha_tentativa && senha_tentativa != -1) {
        bool encontrado = false;
        for (const auto& cliente : clientes) {
            if (cliente.senha == senha_tentativa) {
                encontrado = true;
                if (cliente.situacao == 'P') {
                    std::cout << cliente.nome << ", seja bem-vindo(a)!\n";
                } else {
                    std::cout << "Nao esta esquecendo de algo, " << cliente.nome << "? Procure a recepcao!\n";
                }
                break;
            }
        }

        if (!encontrado) {
            std::cout << "Seja bem-vindo(a)! Procure a recepcao!\n";
        }
    }

    return 0;
}

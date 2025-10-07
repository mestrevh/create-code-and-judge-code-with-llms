/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct Produto {
    std::string nome;
    int quantidade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Produto> estoque;

    for (int i = 0; i < n; ++i) {
        std::string comando;
        std::cin >> comando;

        if (comando == "CADASTRO") {
            std::string nome_produto;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nome_produto);

            auto it = std::find_if(estoque.begin(), estoque.end(),
                                   [&](const Produto& p) { return p.nome == nome_produto; });

            if (it != estoque.end()) {
                std::cout << "Produto ja cadastrado\n";
            } else {
                estoque.push_back({nome_produto, 0});
                std::cout << "Cadastro efetuado com sucesso\n";
            }
        } else if (comando == "ESTOQUE") {
            std::string nome_produto;
            int quantidade;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nome_produto);
            std::cin >> quantidade;

            auto it = std::find_if(estoque.begin(), estoque.end(),
                                   [&](Produto& p) { return p.nome == nome_produto; });

            if (it != estoque.end()) {
                it->quantidade += quantidade;
                std::cout << "Estoque efetuado com sucesso\n";
            } else {
                std::cout << "Produto nao foi cadastrado\n";
            }
        } else if (comando == "VENDA") {
            std::string nome_produto;
            int quantidade;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nome_produto);
            std::cin >> quantidade;

            auto it = std::find_if(estoque.begin(), estoque.end(),
                                   [&](Produto& p) { return p.nome == nome_produto; });

            if (it != estoque.end()) {
                if (it->quantidade >= quantidade) {
                    it->quantidade -= quantidade;
                    std::cout << "Venda realizada com sucesso\n";
                } else {
                    std::cout << "Nao ha estoque para a venda\n";
                }
            } else {
                std::cout << "Produto nao foi cadastrado\n";
            }
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Comando nao reconhecido\n";
        }
    }

    for (const auto& p : estoque) {
        std::cout << p.nome << ": " << p.quantidade << "\n";
    }

    return 0;
}

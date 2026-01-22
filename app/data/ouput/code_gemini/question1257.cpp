/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Produto {
    std::string nome;
    int quantidade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Produto> inventario;

    for (int i = 0; i < n; ++i) {
        std::string comando;
        std::cin >> comando;

        if (comando == "CADASTRO") {
            std::string nomeProduto;
            std::cin.ignore();
            std::getline(std::cin, nomeProduto);

            bool encontrado = false;
            for (const auto& p : inventario) {
                if (p.nome == nomeProduto) {
                    encontrado = true;
                    break;
                }
            }

            if (encontrado) {
                std::cout << "Produto ja cadastrado\n";
            } else {
                inventario.push_back({nomeProduto, 0});
                std::cout << "Produto cadastrado com sucesso\n";
            }
        } else if (comando == "VENDA") {
            std::string nomeProduto;
            int quantidade;
            std::cin.ignore();
            std::getline(std::cin, nomeProduto);
            std::cin >> quantidade;

            int index = -1;
            for (size_t j = 0; j < inventario.size(); ++j) {
                if (inventario[j].nome == nomeProduto) {
                    index = j;
                    break;
                }
            }

            if (index == -1) {
                std::cout << "Produto nao foi cadastrado\n";
            } else {
                if (inventario[index].quantidade >= quantidade) {
                    inventario[index].quantidade -= quantidade;
                    std::cout << "Venda realizada com sucesso\n";
                } else {
                    std::cout << "Nao ha estoque para a venda\n";
                }
            }
        } else if (comando == "ESTOQUE") {
            std::string nomeProduto;
            int quantidade;
            std::cin.ignore();
            std::getline(std::cin, nomeProduto);
            std::cin >> quantidade;

            int index = -1;
            for (size_t j = 0; j < inventario.size(); ++j) {
                if (inventario[j].nome == nomeProduto) {
                    index = j;
                    break;
                }
            }

            if (index == -1) {
                std::cout << "Produto nao foi cadastrado\n";
            } else {
                inventario[index].quantidade += quantidade;
                std::cout << "Estoque realizado com sucesso\n";
            }
        } else {
            std::cout << "Comando invalido\n";
        }
    }

    for (const auto& p : inventario) {
        std::cout << p.nome << ": " << p.quantidade << "\n";
    }

    return 0;
}

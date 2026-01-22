/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, int> estoque;

    for (int i = 0; i < n; ++i) {
        std::string comando;
        std::getline(std::cin, comando);

        if (comando == "Registro") {
            std::string nomeProduto;
            std::getline(std::cin, nomeProduto);
            if (estoque.count(nomeProduto)) {
                std::cout << "Produto ja registrado\n";
            } else {
                estoque[nomeProduto] = 0;
                std::cout << "Produto registrado com sucesso\n";
            }
        } else if (comando == "Venda" || comando == "Recarga") {
            std::string nomeProduto;
            std::getline(std::cin, nomeProduto);
            if (estoque.find(nomeProduto) == estoque.end()) {
                std::cout << "Produto nao registrado\n";
            } else {
                int quantidade;
                std::cin >> quantidade;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (quantidade < 0) {
                    std::cout << "Comando invalido\n";
                } else {
                    if (comando == "Venda") {
                        if (estoque[nomeProduto] >= quantidade) {
                            estoque[nomeProduto] -= quantidade;
                            std::cout << "Venda realizada com sucesso\n";
                        } else {
                            std::cout << "Sem estoque para a Venda\n";
                        }
                    } else { // Recarga
                        estoque[nomeProduto] += quantidade;
                        std::cout << "Recarga realizada com sucesso\n";
                    }
                }
            }
        } else {
            std::cout << "Comando invalido\n";
        }
    }

    for (const auto& par : estoque) {
        std::cout << par.first << ": " << par.second << "\n";
    }

    return 0;
}

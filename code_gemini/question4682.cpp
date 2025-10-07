/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Funcionario {
    std::string nome;
    double salario;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(2);

    std::vector<Funcionario> funcionarios;
    int opcao;

    while (std::cin >> opcao && opcao != 0) {
        switch (opcao) {
            case 1: {
                Funcionario novo_funcionario;
                std::cin >> novo_funcionario.nome >> novo_funcionario.salario;
                funcionarios.push_back(novo_funcionario);
                break;
            }
            case 2: {
                if (funcionarios.empty()) {
                    std::cout << std::endl;
                } else {
                    for (size_t i = 0; i < funcionarios.size(); ++i) {
                        std::cout << i + 1 << ". " << funcionarios[i].nome << std::endl;
                        std::cout << funcionarios[i].salario << std::endl;
                    }
                    std::cout << std::endl;
                }
                break;
            }
            case 3: {
                std::string nome_busca;
                std::cin >> nome_busca;
                bool encontrado = false;
                for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
                    if (it->nome == nome_busca) {
                        funcionarios.erase(it);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Funcionario nao encontrado." << std::endl;
                }
                break;
            }
            case 4: {
                std::string nome_busca;
                double novo_salario;
                std::cin >> nome_busca >> novo_salario;
                bool encontrado = false;
                for (auto &func : funcionarios) {
                    if (func.nome == nome_busca) {
                        func.salario = novo_salario;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Funcionario nao encontrado." << std::endl;
                }
                break;
            }
            default: {
                std::cout << "Opcao invalida" << std::endl;
                break;
            }
        }
    }

    return 0;
}

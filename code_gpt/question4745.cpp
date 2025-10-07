/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Funcionario {
    std::string nome;
    int idade;
    double salario;
};

bool comparaIdade(const Funcionario &a, const Funcionario &b) {
    return a.idade < b.idade;
}

bool comparaSalario(const Funcionario &a, const Funcionario &b) {
    return a.salario < b.salario;
}

int main() {
    std::vector<Funcionario> funcionarios;
    int opcao;

    while (std::cin >> opcao) {
        if (opcao == 1) {
            Funcionario f;
            std::cin.ignore();
            std::getline(std::cin, f.nome);
            std::cin >> f.idade >> f.salario;
            funcionarios.push_back(f);
        } else if (opcao == 2) {
            std::cout << "Ordenado por idade:\n";
            std::sort(funcionarios.begin(), funcionarios.end(), comparaIdade);
            for (size_t i = 0; i < funcionarios.size(); ++i) {
                std::cout << " " << i + 1 << " " << funcionarios[i].nome << "\n      " << funcionarios[i].idade << "\n      " << std::fixed << std::setprecision(2) << funcionarios[i].salario << "\n";
            }
        } else if (opcao == 3) {
            std::cout << "Ordenado por salario:\n";
            std::sort(funcionarios.begin(), funcionarios.end(), comparaSalario);
            for (size_t i = 0; i < funcionarios.size(); ++i) {
                std::cout << " " << i + 1 << " " << funcionarios[i].nome << "\n      " << funcionarios[i].idade << "\n      " << std::fixed << std::setprecision(2) << funcionarios[i].salario << "\n";
            }
        } else if (opcao == 4) {
            std::cout << "Saindo...\n";
            break;
        }
    }

    return 0;
}

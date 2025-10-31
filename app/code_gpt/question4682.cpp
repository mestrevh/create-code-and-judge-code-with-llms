/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Funcionario {
    string nome;
    double salario;
};

vector<Funcionario> funcionarios;

void adicionarFuncionario(const string& nome, double salario) {
    funcionarios.push_back({nome, salario});
}

void exibirFuncionarios() {
    if (funcionarios.empty()) {
        cout << endl;
        return;
    }
    for (size_t i = 0; i < funcionarios.size(); ++i) {
        cout << i + 1 << ". " << funcionarios[i].nome << "\n" << fixed << setprecision(2) << funcionarios[i].salario << "\n";
    }
    cout << endl;
}

void removerFuncionario(const string& nome) {
    auto it = remove_if(funcionarios.begin(), funcionarios.end(), [&](const Funcionario& f) {
        return f.nome == nome;
    });
    if (it == funcionarios.end()) {
        cout << "Funcionario nao encontrado.\n";
    } else {
        funcionarios.erase(it, funcionarios.end());
    }
}

void alterarSalario(const string& nome, double novoSalario) {
    for (auto& f : funcionarios) {
        if (f.nome == nome) {
            f.salario = novoSalario;
            return;
        }
    }
    cout << "Funcionario nao encontrado.\n";
}

int main() {
    int opcao;
    string nome;
    double salario;

    while (true) {
        cin >> opcao;
        if (opcao == 0) break;
        switch (opcao) {
            case 1:
                cin >> nome >> salario;
                adicionarFuncionario(nome, salario);
                break;
            case 2:
                exibirFuncionarios();
                break;
            case 3:
                cin >> nome;
                removerFuncionario(nome);
                break;
            case 4:
                cin >> nome >> salario;
                alterarSalario(nome, salario);
                break;
            default:
                cout << "Opcao invalida\n";
        }
    }
    return 0;
}

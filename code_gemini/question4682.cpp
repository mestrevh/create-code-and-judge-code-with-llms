/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Funcionario {
    string nome;
    double salario;
};

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    while (cin >> opcao && opcao != 0) {
        if (opcao == 1) {
            Funcionario novoFuncionario;
            cin >> novoFuncionario.nome >> novoFuncionario.salario;
            funcionarios.push_back(novoFuncionario);
        } else if (opcao == 2) {
            if (funcionarios.empty()) {
                cout << endl;
            } else {
                for (int i = 0; i < funcionarios.size(); ++i) {
                    cout << i + 1 << ". " << funcionarios[i].nome << endl;
                    cout << fixed << setprecision(2) << funcionarios[i].salario << endl;
                }
                cout << endl;
            }
        } else if (opcao == 3) {
            string nome;
            cin >> nome;
            bool encontrado = false;
            for (int i = 0; i < funcionarios.size(); ++i) {
                if (funcionarios[i].nome == nome) {
                    funcionarios.erase(funcionarios.begin() + i);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Funcionario nao encontrado." << endl;
            }
        } else if (opcao == 4) {
            string nome;
            double novoSalario;
            cin >> nome >> novoSalario;
            bool encontrado = false;
            for (int i = 0; i < funcionarios.size(); ++i) {
                if (funcionarios[i].nome == nome) {
                    funcionarios[i].salario = novoSalario;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Funcionario nao encontrado." << endl;
            }
        } else {
            cout << "Opcao invalida" << endl;
        }
    }

    return 0;
}

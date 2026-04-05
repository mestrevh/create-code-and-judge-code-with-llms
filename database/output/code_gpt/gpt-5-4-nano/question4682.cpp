/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Funcionario {
    string nome;
    double salario;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Funcionario> funcs;
    int opcao;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> opcao) {
        if (opcao == 0) break;

        if (opcao == 1) {
            string nome;
            double salario;
            cin >> nome >> salario;
            funcs.push_back({nome, salario});
        } else if (opcao == 2) {
            for (int i = 0; i < (int)funcs.size(); i++) {
                cout << (i + 1) << ". " << funcs[i].nome << "\n";
                cout << funcs[i].salario << "\n";
            }
            cout << "\n";
        } else if (opcao == 3) {
            string nome;
            double novoSalario;
            cin >> nome >> novoSalario;
            bool achou = false;
            for (auto &f : funcs) {
                if (f.nome == nome) {
                    f.salario = novoSalario;
                    achou = true;
                    break;
                }
            }
            if (!achou) {
                cout << "Funcionario nao encontrado.\n";
            }
        } else if (opcao == 4) {
            string nome;
            cin >> nome;
            for (int i = 0; i < (int)funcs.size(); i++) {
                if (funcs[i].nome == nome) {
                    funcs.erase(funcs.begin() + i);
                    break;
                }
            }
        } else {
            cout << "Opcao invalida\n";
        }
    }

    return 0;
}
/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Funcionario {
    string nome;
    int idade;
    double salario;
};

bool compararPorIdade(const Funcionario& a, const Funcionario& b) {
    return a.idade < b.idade;
}

bool compararPorSalario(const Funcionario& a, const Funcionario& b) {
    return a.salario < b.salario;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    while (cin >> opcao && opcao != 4) {
        if (opcao == 1) {
            Funcionario f;
            cin.ignore(); 
            getline(cin, f.nome);
            cin >> f.idade >> f.salario;
            funcionarios.push_back(f);
        } else if (opcao == 2) {
            cout << endl << "Ordenado por idade:" << endl << endl;
            sort(funcionarios.begin(), funcionarios.end(), compararPorIdade);
            for (int i = 0; i < funcionarios.size(); ++i) {
                cout << " " << i + 1 << " " << funcionarios[i].nome << endl;
                cout << "      " << funcionarios[i].idade << endl;
                cout << "      " << fixed << setprecision(2) << funcionarios[i].salario << endl;
            }
        } else if (opcao == 3) {
            cout << endl << "Ordenado por salario:" << endl << endl;
            sort(funcionarios.begin(), funcionarios.end(), compararPorSalario);
            for (int i = 0; i < funcionarios.size(); ++i) {
                cout << " " << i + 1 << " " << funcionarios[i].nome << endl;
                cout << "      " << funcionarios[i].idade << endl;
                cout << "      " << fixed << setprecision(2) << funcionarios[i].salario << endl;
            }
        }
    }

    cout << "Saindo..." << endl;

    return 0;
}

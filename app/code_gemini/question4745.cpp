/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Funcionario {
    string nome;
    int idade;
    double salario;
};

void exibir(const vector<Funcionario>& vec, const string& titulo) {
    cout << endl << titulo << endl << endl;
    cout << fixed << setprecision(2);
    int index = 1;
    for (const auto& f : vec) {
        cout << " " << index++ << " " << f.nome << endl;
        cout << "      " << f.idade << endl;
        cout << "      " << f.salario << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Funcionario> funcionarios;
    int option;

    while (cin >> option) {
        if (option == 1) {
            Funcionario f;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, f.nome);
            cin >> f.idade;
            cin >> f.salario;
            funcionarios.push_back(f);
        } else if (option == 2) {
            vector<Funcionario> temp = funcionarios;
            sort(temp.begin(), temp.end(), [](const Funcionario& a, const Funcionario& b) {
                if (a.idade != b.idade) {
                    return a.idade < b.idade;
                }
                return false; 
            });
            exibir(temp, "Ordenado por idade:");
        } else if (option == 3) {
            vector<Funcionario> temp = funcionarios;
            sort(temp.begin(), temp.end(), [](const Funcionario& a, const Funcionario& b) {
                if (a.salario != b.salario) {
                    return a.salario < b.salario;
                }
                return false;
            });
            exibir(temp, "Ordenado por salario:");
        } else if (option == 4) {
            cout << endl << "Saindo..." << endl;
            break;
        }
    }

    return 0;
}

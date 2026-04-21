/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Funcionario {
    string nome;
    double salario;
};

void limparMemoria(vector<Funcionario*>& db) {
    for (auto f : db) {
        delete f;
    }
    db.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Funcionario*> db;
    int opt;

    while (cin >> opt && opt != 0) {
        if (opt == 1) {
            string nome;
            double salario;
            if (cin >> nome >> salario) {
                Funcionario* f = new Funcionario;
                f->nome = nome;
                f->salario = salario;
                db.push_back(f);
            }
        } else if (opt == 2) {
            if (db.empty()) {
                cout << "\n";
            } else {
                for (int i = 0; i < (int)db.size(); ++i) {
                    cout << i + 1 << ". " << db[i]->nome << "\n";
                    cout << fixed << setprecision(2) << db[i]->salario << "\n";
                }
                cout << "\n";
            }
        } else if (opt == 3) {
            string nome;
            if (cin >> nome) {
                bool encontrado = false;
                for (auto it = db.begin(); it != db.end(); ++it) {
                    if ((*it)->nome == nome) {
                        delete *it;
                        db.erase(it);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Funcionario nao encontrado.\n";
                }
            }
        } else if (opt == 4) {
            string nome;
            double novoSalario;
            if (cin >> nome >> novoSalario) {
                bool encontrado = false;
                for (int i = 0; i < (int)db.size(); ++i) {
                    if (db[i]->nome == nome) {
                        db[i]->salario = novoSalario;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Funcionario nao encontrado.\n";
                }
            }
        } else {
            cout << "Opcao invalida\n";
        }
    }

    limparMemoria(db);

    return 0;
}
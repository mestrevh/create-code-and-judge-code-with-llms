/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    queue<pair<string, stack<string>>> materias;
    string tipo, nome;

    while (cin >> tipo >> nome) {
        if (tipo == "M") {
            stack<string> atividades;
            materias.push({nome, atividades});
        } else {
            materias.back().second.push(nome);
        }
    }

    while (!materias.empty()) {
        if (materias.front().second.empty()) {
            materias.pop();
        } else {
            materias.front().second.pop();
        }

        queue<pair<string, stack<string>>> temp = materias;
        while (!temp.empty()) {
            cout << "Materia: " << temp.front().first << endl;
            stack<string> atividades_temp = temp.front().second;
            stack<string> atividades_invertidas;
            while (!atividades_temp.empty()) {
                atividades_invertidas.push(atividades_temp.top());
                atividades_temp.pop();
            }
            while (!atividades_invertidas.empty()) {
                cout << "    Atividade: " << atividades_invertidas.top() << endl;
                atividades_invertidas.pop();
            }
            temp.pop();
        }
        cout << "_________________" << endl << endl;
    }

    return 0;
}

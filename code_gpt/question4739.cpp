/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Materia {
    string nome;
    stack<string> atividades;
};

int main() {
    queue<Materia> fila;
    string linha;
    while (getline(cin, linha)) {
        if (linha.empty()) break;
        stringstream ss(linha);
        char tipo;
        ss >> tipo;
        if (tipo == 'M') {
            string nome;
            ss >> nome;
            fila.push({nome});
        } else if (tipo == 'A') {
            string atividade;
            ss >> atividade;
            if (!fila.empty()) {
                fila.back().atividades.push(atividade);
            }
        }
    }

    while (!fila.empty()) {
        Materia& atual = fila.front();
        if (atual.atividades.empty()) {
            fila.pop();
        } else {
            atual.atividades.pop();
        }

        for (const auto& m : fila) {
            cout << "Materia: " << m.nome << endl;
            auto atividades = m.atividades;
            while (!atividades.empty()) {
                cout << "    Atividade: " << atividades.top() << endl;
                atividades.pop();
            }
        }
        cout << "_________________" << endl << endl;
    }

    return 0;
}

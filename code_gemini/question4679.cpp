/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<string> turma1, turma2, turma3;
    string nome, linha;
    int turma;

    while (getline(cin, nome)) {
        getline(cin, linha);
        stringstream ss(linha);
        ss >> turma;

        if (turma == 1) {
            turma1.push_back(nome);
        } else if (turma == 2) {
            turma2.push_back(nome);
        } else if (turma == 3) {
            turma3.push_back(nome);
        }
    }

    cout << "Turma 1:" << endl;
    for (const string& aluno : turma1) {
        cout << aluno << endl;
    }

    cout << endl << "Turma 2:" << endl;
    for (const string& aluno : turma2) {
        cout << aluno << endl;
    }

    cout << endl << "Turma 3:" << endl;
    for (const string& aluno : turma3) {
        cout << aluno << endl;
    }

    return 0;
}

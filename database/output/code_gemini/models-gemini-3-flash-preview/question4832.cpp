/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Aluno {
    string nome;
    int faltas;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    list<Aluno> turma;
    int menorFaltas;
    bool inicializado = false;

    for (int i = 0; i < T; ++i) {
        string n;
        int f;
        if (cin >> n >> f) {
            Aluno a;
            a.nome = n;
            a.faltas = f;
            turma.push_back(a);
            
            if (!inicializado) {
                menorFaltas = f;
                inicializado = true;
            } else {
                if (f < menorFaltas) {
                    menorFaltas = f;
                }
            }
        }
    }

    if (inicializado) {
        cout << "O(s) ganhador(es) com " << menorFaltas << " falta(s) é(são):" << "\n";
        for (const auto& aluno : turma) {
            if (aluno.faltas == menorFaltas) {
                cout << aluno.nome << "\n";
            }
        }
    }

    return 0;
}
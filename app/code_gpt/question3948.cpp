/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Monitor {
    int id;
    string nome;
};

struct Aluno {
    string nome;
    int id_monitor;
    vector<int> respostas;
    int pontuacao;
};

int main() {
    int A, B, N;
    cin >> A;
    vector<Monitor> monitores(A);

    for (int i = 0; i < A; ++i) {
        cin >> monitores[i].id;
        cin.ignore();
        getline(cin, monitores[i].nome);
    }

    cin >> B;
    vector<Aluno> alunos(B);

    for (int i = 0; i < B; ++i) {
        cin.ignore();
        getline(cin, alunos[i].nome);
        cin >> alunos[i].id_monitor;
        alunos[i].respostas.resize(9);
        alunos[i].pontuacao = 0;

        for (int j = 0; j < 9; ++j) {
            cin >> alunos[i].respostas[j];
            alunos[i].pontuacao += alunos[i].respostas[j];
        }
    }

    cin >> N;
    
    for (int i = 0; i < B; ++i) {
        if (alunos[i].respostas[(N - 1) * 3 + 2] == 1) {
            alunos[i].pontuacao += 1;
        }
        cout << alunos[i].nome << endl;
        cout << monitores[alunos[i].id_monitor - 1].nome << endl;
        cout << alunos[i].pontuacao << endl;
    }

    return 0;
}

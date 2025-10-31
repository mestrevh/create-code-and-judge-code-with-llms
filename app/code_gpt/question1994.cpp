/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno {
    int matricula;
    string primeiroNome;
    string ultimoNome;
    float media;
    int faltas;
    char status;
};

int main() {
    int N;
    cin >> N;
    vector<Aluno> alunos(N);
    float somaMedias = 0.0;
    int alunosMatriculados = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> alunos[i].matricula >> alunos[i].primeiroNome >> alunos[i].ultimoNome 
             >> alunos[i].media >> alunos[i].faltas >> alunos[i].status;
        somaMedias += alunos[i].media;
        if (alunos[i].status == 'M') {
            alunosMatriculados++;
        }
    }
    
    float mediaTurma = somaMedias / N;
    vector<pair<int, string>> destaques;

    for (int i = 0; i < N; ++i) {
        if (alunos[i].media > mediaTurma && alunos[i].status == 'M' 
            && alunos[i].faltas < (0.1 * N)) {
            destaques.push_back({i + 1, alunos[i].ultimoNome});
        }
    }

    if (destaques.empty()) {
        cout << "VAZIO" << endl;
    } else {
        for (const auto& d : destaques) {
            cout << d.first << ":" << d.second << endl;
        }
    }

    return 0;
}

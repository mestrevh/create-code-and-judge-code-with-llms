/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota;
};

bool compara(const Aluno &a, const Aluno &b) {
    if (a.nota == b.nota) return a.matricula < b.matricula;
    return a.nota < b.nota;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<Aluno> alunos(N);
    float soma = 0.0;

    for (int i = 0; i < N; ++i) {
        string linha;
        getline(cin, linha);
        stringstream ss(linha);
        string token;

        getline(ss, token, '-');
        alunos[i].matricula = stoi(token);

        getline(ss, alunos[i].nome, '-');

        getline(ss, token);
        alunos[i].nota = stof(token);

        soma += alunos[i].nota;
    }

    float media = soma / N;

    vector<Aluno> abaixo, acima;
    for (const auto& aluno : alunos) {
        if (aluno.nota < media) {
            abaixo.push_back(aluno);
        } else {
            acima.push_back(aluno);
        }
    }

    cout << "Alunos abaixo da media:" << endl;
    for (const auto& aluno : abaixo) {
        cout << "Matricula: " << aluno.matricula << " Nome: " << aluno.nome << " Nota: " << fixed << setprecision(1) << aluno.nota << endl;
    }

    cout << "Alunos iguais ou acima da media:" << endl;
    sort(acima.begin(), acima.end(), compara);
    for (const auto& aluno : acima) {
        cout << "Matricula: " << aluno.matricula << " Nome: " << aluno.nome << " Nota: " << fixed << setprecision(1) << aluno.nota << endl;
    }

    cout << "Media = " << fixed << setprecision(2) << media << endl;

    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Aluno {
    string nome;
    double n1, n2, n3;
    double media;
    string situacao;
};

void ordenarAlunos(vector<Aluno>& alunos) {
    sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.nome < b.nome;
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Aluno> alunos(n);

    for (int i = 0; i < n; ++i) {
        cin >> ws;
        getline(cin, alunos[i].nome);
        cin >> alunos[i].n1 >> alunos[i].n2 >> alunos[i].n3;

        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3.0;

        if (alunos[i].media >= 7.0) {
            alunos[i].situacao = "Aprovado";
        } else if (alunos[i].media >= 3.0) {
            alunos[i].situacao = "Final";
        } else {
            alunos[i].situacao = "Reprovado";
        }
    }

    ordenarAlunos(alunos);

    for (int i = 0; i < n; ++i) {
        cout << "Aluno: " << alunos[i].nome << "\n";
        cout << "Media: " << fixed << setprecision(2) << alunos[i].media << "\n";
        cout << "Situcao: " << alunos[i].situacao << "\n";
        if (i < n - 1) {
            cout << "\n";
        }
    }

    return 0;
}
/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int habilidade;
};

int main() {
    int N, T;
    cin >> N >> T;
    vector<Aluno> alunos(N);
    for (int i = 0; i < N; ++i) {
        cin >> alunos[i].nome >> alunos[i].habilidade;
    }
    sort(alunos.begin(), alunos.end(), [](const Aluno &a, const Aluno &b) {
        return a.habilidade > b.habilidade;
    });

    vector<vector<string>> times(T);

    for (int i = 0; i < N; ++i) {
        times[i % T].push_back(alunos[i].nome);
    }

    for (int i = 0; i < T; ++i) {
        sort(times[i].begin(), times[i].end());
        cout << "Time " << i + 1 << "\n";
        for (const auto &nome : times[i]) {
            cout << nome << "\n";
        }
        cout << "\n";
    }
    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    int habilidade;
};

bool compararHabilidade(const Aluno& a, const Aluno& b) {
    return a.habilidade > b.habilidade;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    if (!(cin >> N >> T)) return 0;

    vector<Aluno> alunos(N);
    for (int i = 0; i < N; ++i) {
        cin >> alunos[i].nome >> alunos[i].habilidade;
    }

    sort(alunos.begin(), alunos.end(), compararHabilidade);

    vector<vector<string>> times(T);
    for (int i = 0; i < N; ++i) {
        times[i % T].push_back(alunos[i].nome);
    }

    for (int i = 0; i < T; ++i) {
        sort(times[i].begin(), times[i].end());
        cout << "Time " << i + 1 << "\n";
        for (const string& nome : times[i]) {
            cout << nome << "\n";
        }
        cout << "\n";
    }

    return 0;
}
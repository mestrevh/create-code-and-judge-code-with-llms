/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Aluno {
    string matricula;
    string nome;
};

bool compareAlunos(const Aluno& a, const Aluno& b) {
    return a.nome < b.nome;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<Aluno> alunos(N);
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        size_t pos = s.find('-');
        if (pos != string::npos) {
            alunos[i].matricula = s.substr(0, pos);
            alunos[i].nome = s.substr(pos + 1);
        } else {
            alunos[i].matricula = s;
            cin >> alunos[i].nome;
        }
    }

    sort(alunos.begin(), alunos.end(), compareAlunos);

    if (K >= 1 && K <= (int)alunos.size()) {
        cout << "Matricula: " << alunos[K - 1].matricula << "\n";
        cout << "Nome: " << alunos[K - 1].nome << "\n";
    }

    return 0;
}
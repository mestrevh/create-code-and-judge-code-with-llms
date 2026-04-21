/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    struct Aluno {
        string nome;
        string matricula;
    };

    vector<Aluno> v;
    v.reserve(N);

    for (int i = 0; i < N; i++) {
        string matriculaNome;
        string matricula;
        string nome;
        cin >> matricula;
        cin >> nome;
        v.push_back({nome, matricula});
    }

    sort(v.begin(), v.end(), [](const Aluno& a, const Aluno& b) {
        return a.nome < b.nome;
    });

    int idx = K - 1;
    cout << "Matricula: " << v[idx].matricula << "\n";
    cout << "Nome: " << v[idx].nome << "\n";
    return 0;
}
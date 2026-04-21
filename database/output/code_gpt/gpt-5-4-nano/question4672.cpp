/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    int idade;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Aluno> ate14;
    vector<Aluno> maior14;

    for (int i = 0; i < N; i++) {
        Aluno a;
        cin >> a.nome >> a.idade;
        if (a.idade <= 14) ate14.push_back(a);
        else maior14.push_back(a);
    }

    for (const auto& a : ate14) {
        cout << a.nome << "\n" << a.idade << "\n";
    }
    for (const auto& a : maior14) {
        cout << a.nome << "\n" << a.idade << "\n";
    }

    return 0;
}
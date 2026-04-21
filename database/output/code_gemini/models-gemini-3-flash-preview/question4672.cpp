/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int idade;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Aluno> ate_14;
    vector<Aluno> mais_14;

    for (int i = 0; i < n; ++i) {
        string nome;
        int idade;
        if (!(cin >> nome >> idade)) break;
        if (idade <= 14) {
            ate_14.push_back({nome, idade});
        } else {
            mais_14.push_back({nome, idade});
        }
    }

    for (const auto& aluno : ate_14) {
        cout << aluno.nome << "\n" << aluno.idade << "\n";
    }

    for (const auto& aluno : mais_14) {
        cout << aluno.nome << "\n" << aluno.idade << "\n";
    }

    return 0;
}
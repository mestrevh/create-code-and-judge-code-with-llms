/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    vector<pair<string,int>> alunos;
    alunos.reserve(T);

    for (int i = 0; i < T; i++) {
        string nome;
        int faltas;
        cin >> nome >> faltas;
        alunos.push_back({nome, faltas});
    }

    int menor = alunos[0].second;
    for (int i = 1; i < T; i++) {
        if (alunos[i].second < menor) menor = alunos[i].second;
    }

    bool first = true;
    cout << "O(s) ganhador(es) com " << menor << " falta(s) é(são):\n";
    for (int i = 0; i < T; i++) {
        if (alunos[i].second == menor) {
            cout << alunos[i].first << "\n";
            first = false;
        }
    }

    return 0;
}
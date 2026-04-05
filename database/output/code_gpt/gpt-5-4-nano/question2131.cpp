/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, E;
    if (!(cin >> P)) return 0;
    cin >> E;

    vector<vector<int>> votos(E, vector<int>(P));
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < P; j++) cin >> votos[i][j];
    }

    vector<int> soma(P, 0);
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < P; j++) soma[j] += votos[i][j];
    }

    for (int j = 0; j < P; j++) {
        cout << "Princesa " << (j + 1) << ": " << soma[j] << " voto(s)\n";
    }

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double valorSplit;
    if (!(cin >> valorSplit)) return 0;

    int totalItensTrocados = 0;
    double soma = 0.0;

    for (int i = 0; i < 6; i++) {
        double valorPresente;
        int qtd;
        cin >> valorPresente >> qtd;
        soma += valorPresente * max(0, qtd - 1);
        totalItensTrocados += max(0, qtd - 1);
    }

    const double EPS = 1e-9;
    bool consegue = (soma + EPS >= valorSplit);

    cout << totalItensTrocados << "\n";
    cout << (consegue ? "SIM" : "NAO");
    return 0;
}
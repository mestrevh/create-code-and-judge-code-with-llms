/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double sum = 0.0;
    vector<double> a(6);

    for (int i = 0; i < 6; i++) {
        cout << "Digite pontuacao da partida " << (i + 1) << ":";
        if (!(cin >> a[i])) return 0;
        if (a[i] < 0) {
            cout << "Valores negativos nao sao permitidos.";
            return 0;
        }
        sum += a[i];
    }

    cout << "Total de pontos: " << sum << ". O competidor esta classificado.";
    return 0;
}
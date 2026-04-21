/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double distancia;
    char tipo;
    if (!(cin >> distancia >> tipo)) return 0;

    double kmPorLitro = 0.0;
    if (tipo == 'A') kmPorLitro = 12.0;
    else if (tipo == 'B') kmPorLitro = 9.0;
    else if (tipo == 'C') kmPorLitro = 8.0;
    else {
        cout << "Tipo inválido!";
        return 0;
    }

    double litros = distancia / kmPorLitro;
    cout << fixed << setprecision(2) << litros;
    return 0;
}
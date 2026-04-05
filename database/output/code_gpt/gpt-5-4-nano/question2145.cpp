/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char nacionalidade, ocupacao;
    long long quantidade;
    long long calibre;

    if (!(cin >> nacionalidade)) return 0;
    cin >> ocupacao;
    cin >> quantidade >> calibre;

    bool liberado = false;

    if (nacionalidade == 'E') {
        liberado = (quantidade == 0 && calibre == 0);
    } else { 
        if (ocupacao == 'M') {
            liberado = true;
        } else if (ocupacao == 'T' || ocupacao == 'O') {
            liberado = (quantidade == 1 && calibre <= 22);
        } else if (ocupacao == 'C') {
            liberado = (quantidade <= 2 && calibre <= 38);
        }
    }

    cout << (liberado ? "Liberado" : "Barrado") << "\n";
    return 0;
}
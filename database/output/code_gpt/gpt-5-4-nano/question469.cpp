/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string vencedor;
    int pontosR = 0, pontosH = 0;
    int vitoriasR = 0, vitoriasH = 0;

    for (int i = 0; i < 5; i++) {
        int r, h;
        if (!(cin >> r)) return 0;
        cin >> h;
        pontosR += r;
        pontosH += h;
        if (r > h) vitoriasR++;
        else if (h > r) vitoriasH++;
    }

    if (vitoriasR > vitoriasH) vencedor = "REINALDO";
    else if (vitoriasH > vitoriasR) vencedor = "HELENA";
    else {
        if (pontosR > pontosH) vencedor = "REINALDO";
        else if (pontosH > pontosR) vencedor = "HELENA";
        else vencedor = "EMAPTE";
    }

    if (vencedor == "EMAPTE") cout << "EMPATE";
    else cout << vencedor;

    return 0;
}
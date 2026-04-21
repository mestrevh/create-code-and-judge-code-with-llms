/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long C, L;
    string Tipo;
    long long X, Y;
    if (!(cin >> C)) return 0;
    if (!(cin >> L)) return 0;
    if (!(cin >> Tipo)) return 0;
    if (!(cin >> X)) return 0;
    if (!(cin >> Y)) return 0;

    bool inCourt = (X == C) && (Y >= 1 && Y <= L);
    if (!inCourt) {
        cout << "A bola foi para fora";
        return 0;
    }

    long long y25_start = 1;
    long long y25_end = L / 4;
    long long y50_start = y25_end + 1;
    long long y50_end = 3 * (L / 4);

    bool ok = false;
    if (Tipo == "Saque") {
        long long saqueL = L / 4;
        long long saqueR = (3 * L) / 4;
        ok = (Y >= saqueL && Y <= saqueR);
    } else {
        ok = (Y >= 1 && Y <= L);
    }

    cout << (ok ? "A bola foi rebatida" : "A bola foi para fora");
    return 0;
}
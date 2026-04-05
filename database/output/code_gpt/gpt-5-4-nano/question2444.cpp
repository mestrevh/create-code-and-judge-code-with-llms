/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long V, E;
    string A;
    if (!(cin >> V)) return 0;
    cin >> E;
    cin >> A;

    if (A != "pedra" && A != "graveto") {
        cout << "Tarzan nao consegue lutar sem armas... Ele foi capturado";
        return 0;
    }

    long long dmgV = 0, dmgE = 0;
    if (A == "pedra") {
        dmgV = 15;
        dmgE = 13;
    } else {
        dmgV = 10;
        dmgE = 8;
    }

    if (dmgV <= 0 || dmgE <= 0) {
        cout << "Tarzan nao consegue lutar sem armas... Ele foi capturado";
        return 0;
    }

    long long t = (E + dmgE - 1) / dmgE;
    long long need = (V + dmgV - 1) / dmgV;

    if (need <= t) {
        cout << "Tarzan venceu o invasor e o expulsou de sua floresta";
    } else {
        cout << "Tarzan nao foi capaz de derrotar o invasor... Ele foi capturado";
    }
    return 0;
}
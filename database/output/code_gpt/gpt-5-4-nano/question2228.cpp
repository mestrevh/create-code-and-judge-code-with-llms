/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double I;
    long double A;
    long double D;
    long double P;
    string S;

    if (!(cin >> I)) return 0;
    cin >> A >> D >> P >> S;

    if (S == "Sim") {
        P += 50;
        I += 5;
    }

    long double maxHeight = (I * I) / (4.0L * A * A + 1e-12L);
    long double requiredHeight = 100.0L - D / 10.0L;

    if (maxHeight >= requiredHeight) cout << "Voce consegue";
    else cout << "Isso e perda de tempo";

    return 0;
}
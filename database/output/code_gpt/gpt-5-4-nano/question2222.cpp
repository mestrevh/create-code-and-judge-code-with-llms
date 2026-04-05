/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double I, A;
    long double D, P;
    string S;

    if (!(cin >> I)) return 0;
    cin >> A >> D >> P >> S;

    if (S == "Sim") {
        P += 50;
        I += 5;
    }

    long double denom = sqrt((double)A) + D / 2.0L + P / 3.0L;
    long double height = (I * I * I) / denom;

    cout << (height >= 100.0L ? "Voce consegue" : "Isso e perda de tempo");
    return 0;
}
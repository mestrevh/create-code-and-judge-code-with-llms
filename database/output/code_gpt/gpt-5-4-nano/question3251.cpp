/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double A, B, C, D, E;
    if (!(cin >> A >> B >> C >> D >> E)) return 0;

    long double result = (A + B + C) / (D + E);

    cout << fixed << setprecision(2) << (double)result;
    return 0;
}
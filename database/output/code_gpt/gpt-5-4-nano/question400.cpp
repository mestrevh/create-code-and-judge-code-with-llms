/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double CalculaMulta(int v) {
    const int limite = 50;
    if (v <= limite) return 0.0;

    if (v <= 60) return 230.0;

    if (v <= 70) return 340.0;

    double exced = v - limite;
    return exced * 19.28;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v;
    if (!(cin >> v)) return 0;

    cout.setf(ios::fixed);
    cout << setprecision(2) << CalculaMulta(v) << "\n";
    return 0;
}
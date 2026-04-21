/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double salario;
    if (!(cin >> salario)) return 0;

    long double novo = salario;
    if (salario > 500.0L) novo = salario * 1.10L;
    else if (salario > 300.0L) novo = salario * 1.07L;
    else novo = salario * 1.05L;

    cout << fixed << setprecision(2) << (double)novo << "\n";
    return 0;
}
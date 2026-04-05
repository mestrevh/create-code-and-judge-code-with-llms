/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario;
    if (!(cin >> salario)) return 0;

    double bonus = 0.0;
    if (salario <= 5000.0) bonus = salario * 0.05;
    else if (salario <= 12000.0) bonus = salario * 0.12;
    else bonus = 0.0;

    double aux = (salario <= 6000.0) ? 150.0 : 100.0;

    double novo = salario + bonus + aux;

    cout << fixed << setprecision(2) << novo << "\n";
    return 0;
}
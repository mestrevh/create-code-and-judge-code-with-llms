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
    int horas;
    if (!(cin >> salario >> horas)) return 0;

    double horaBase = salario / 44.0;
    double adicional = horas * 0.10 * horaBase;
    double salarioFinal = salario + horas * horaBase + adicional;

    cout << fixed << setprecision(2) << salarioFinal;
    return 0;
}
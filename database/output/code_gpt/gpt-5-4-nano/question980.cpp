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

    double reajustado = salario;
    if (salario < 1000.0) {
        reajustado = salario * 1.30;
    } else if (salario >= 1000.0 && salario <= 2000.0) {
        reajustado = salario * 1.10;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << reajustado << "\n";
    return 0;
}
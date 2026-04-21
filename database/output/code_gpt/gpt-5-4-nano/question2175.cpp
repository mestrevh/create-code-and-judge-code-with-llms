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

    double imposto = 0.0;

    if (salario <= 2000.0) {
        cout << "Isento";
        return 0;
    }

    double base1 = min(salario, 3000.0) - 2000.0;
    if (base1 > 0) imposto += base1 * 0.08;

    if (salario > 3000.0) {
        double base2 = min(salario, 5000.0) - 3000.0;
        if (base2 > 0) imposto += base2 * 0.18;
    }

    if (salario > 5000.0) {
        double base3 = salario - 5000.0;
        if (base3 > 0) imposto += base3 * 0.28;
    }

    cout << fixed << setprecision(2);
    cout << "R$ " << imposto;
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double saldoInicial, totalDebitos, totalCreditos;
    if (!(cin >> saldoInicial)) return 0;
    cin >> totalDebitos >> totalCreditos;

    long double saldoFinal = saldoInicial - totalDebitos + totalCreditos;

    cout.setf(std::ios::fmtflags(0), std::ios::floatfield);
    cout << "Saldo final:" << "\n";

    if (saldoFinal > 0) {
        cout << "Saldo positivo em R$ " << (double)saldoFinal;
    } else if (saldoFinal < 0) {
        cout << "Saldo negativo em R$ " << (double)saldoFinal;
    } else {
        cout << "Saldo Zero";
    }
    return 0;
}
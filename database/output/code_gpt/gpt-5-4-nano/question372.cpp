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
    long long horas;
    if (!(cin >> salario)) return 0;
    cin >> horas;

    double total = salario + salario * 0.05 * horas;
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}
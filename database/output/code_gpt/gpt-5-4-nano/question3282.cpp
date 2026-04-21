/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario, percentual;
    if (!(cin >> salario >> percentual)) return 0;

    double aumento = salario * (percentual / 100.0);
    double novoSalario = salario + aumento;

    cout.setf(ios::fixed);
    cout << setprecision(2) << aumento << "\n" << novoSalario << "\n";
    return 0;
}
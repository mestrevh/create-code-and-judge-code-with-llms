/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    double salario, vendas;

    if (!getline(cin, nome)) return 0;
    if (!(cin >> salario)) return 0;
    if (!(cin >> vendas)) return 0;

    double total = salario + 0.15 * vendas;

    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << total << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double fatura;
    if (!(cin >> fatura)) return 0;

    double marco = fatura / 2.0;
    double abril = marco + (fatura - marco) * 1.065;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "Valor total da fatura: R$ " << fatura << "\n";
    cout << "Valor a pagar em Marco: R$ " << marco << "\n";
    cout << "Valor a pagar em Abril: R$ " << abril << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double reais;
    if (!(cin >> reais)) return 0;

    const double usd = 3.87;
    const double eur = 4.35;

    double dolar = reais / usd;
    double euro = reais / eur;

    cout << fixed << setprecision(2);
    cout << "Digite o valor em reais:\n";
    cout << "Valor convertido em dolar: " << dolar << "\n";
    cout << "Valor convertido em euro: " << euro;
    return 0;
}
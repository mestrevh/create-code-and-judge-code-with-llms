/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double real;
    cout << "Digite o valor em reais: \n";
    if (!(cin >> real)) return 0;

    const double dolar = 3.87;
    const double euro = 4.35;

    double vD = real / dolar;
    double vE = real / euro;

    cout << "Valor convertido em dolar: " << fixed << setprecision(4) << vD << "\n";
    cout << "Valor convertido em euro: " << fixed << setprecision(4) << vE << "\n";

    return 0;
}
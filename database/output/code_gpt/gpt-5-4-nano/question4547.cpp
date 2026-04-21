/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double kwh;
    if (!(cin >> kwh)) return 0;

    const double pricePerKWh = 0.75;
    const double ratePublicLighting = 0.05;

    double consumo = kwh * pricePerKWh;
    double taxa = consumo * ratePublicLighting;
    double total = consumo + taxa;

    cout << fixed << setprecision(3);
    cout << "Valor do consumo: R$ " << consumo << "\n";
    cout << "Valor taxa iluminacao: R$ " << taxa << "\n";
    cout << "Valor total a pagar: R$ " << total << "\n";

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double U;
    if (!(cin >> U)) return 0;

    long double pricePerKWh;
    if (U <= 99) pricePerKWh = 1.35L;
    else if (U <= 299) pricePerKWh = 1.55L;
    else if (U <= 574) pricePerKWh = 1.75L;
    else pricePerKWh = 2.15L;

    long double total = U * pricePerKWh;
    if (U > 300) total *= 1.10L;
    if (total < 35.0L) total = 35.0L;

    cout << fixed << setprecision(2) << total << "\n" << fixed << setprecision(2) << pricePerKWh << "\n";
    return 0;
}
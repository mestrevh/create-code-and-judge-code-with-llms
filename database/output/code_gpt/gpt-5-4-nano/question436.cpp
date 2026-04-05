/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mulheres, homens;
    if (!(cin >> mulheres >> homens)) return 0;

    const double vinho = 10.0;
    const double panetone = 8.50;

    double total = (mulheres + homens) * vinho + mulheres * panetone;
    double media = total / (mulheres + homens);

    cout << fixed << setprecision(2) << total << "\n" << media << "\n";
    return 0;
}
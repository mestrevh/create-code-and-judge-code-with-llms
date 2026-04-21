/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    long double liters = a * 0.35L + b * 0.6L + c * 2.0L;

    cout << fixed << setprecision(1) << "Foram comprados " << liters << " litros de refrigerante.";
    return 0;
}
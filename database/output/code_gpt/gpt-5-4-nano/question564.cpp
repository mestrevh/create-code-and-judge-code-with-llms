/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double vmax, v;
    if (!(cin >> vmax >> v)) return 0;

    double ratio = (v - vmax) / vmax;
    double multa = 0.0;
    int pontos = 0;

    const double m1 = 85.13;
    const double m2 = 127.69;
    const double m3 = 574.62;

    if (v > vmax) {
        if (ratio <= 0.20) {
            multa = m1;
            pontos = 4;
        } else if (ratio <= 0.50) {
            multa = m2;
            pontos = 5;
        } else {
            multa = m3;
            pontos = 7;
        }
    }

    cout << fixed << setprecision(2) << multa << "\n" << pontos << "\n";
    return 0;
}
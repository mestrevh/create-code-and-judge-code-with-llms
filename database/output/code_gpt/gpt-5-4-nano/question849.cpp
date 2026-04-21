/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double VolumeEsfera(double R) {
    const double pi = 3.1416;
    return (4.0 * pi * R * R * R) / 3.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double r1, r2, r3;
    if (!(cin >> r1)) return 0;
    cin >> r2 >> r3;

    cout << fixed << setprecision(2);
    cout << VolumeEsfera(r1) << "\n";
    cout << VolumeEsfera(r2) << "\n";
    cout << VolumeEsfera(r3) << "\n";
    return 0;
}
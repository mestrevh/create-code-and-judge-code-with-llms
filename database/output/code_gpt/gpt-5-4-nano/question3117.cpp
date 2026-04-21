/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double X, Z;
    if (!(cin >> X)) return 0;
    cin >> Z;

    const double hx = 34, hz = 220;
    const double kx = 0, kz = 0;
    const double sx = 140, sz = 456;

    auto dist2d = [&](double ax, double az, double bx, double bz) {
        double dx = ax - bx, dz = az - bz;
        return sqrt(dx * dx + dz * dz);
    };

    double H = dist2d(X, Z, hx, hz);
    double K = dist2d(X, Z, kx, kz);
    double S = dist2d(X, Z, sx, sz);

    cout << fixed << setprecision(2);
    cout << "Distancia para Hogsmeade: " << H << "\n";
    cout << "Distancia para Kakariko: " << K << "\n";
    cout << "Distancia para Solitude: " << S << "\n";

    return 0;
}
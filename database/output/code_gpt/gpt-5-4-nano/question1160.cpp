/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, z;
    if (!(cin >> x >> z)) return 0;

    const long long Hx = 34, Hz = 220;
    const long long Kx = 0, Kz = 0;
    const long long Sx = 140, Sz = 456;

    auto dist = [&](long long ax, long long az) -> double {
        long long dx = x - ax;
        long long dz = z - az;
        return sqrt((double)dx * dx + (double)dz * dz);
    };

    double dH = dist(Hx, Hz);
    double dK = dist(Kx, Kz);
    double dS = dist(Sx, Sz);

    cout << fixed << setprecision(2);
    cout << "Distancia para Hogsmeade: " << dH << "\n";
    cout << "Distancia para Kakariko: " << dK << "\n";
    cout << "Distancia para Solitude: " << dS << "\n";
    return 0;
}
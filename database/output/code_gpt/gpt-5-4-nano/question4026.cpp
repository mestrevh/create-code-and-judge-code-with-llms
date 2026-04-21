/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a1, b1, a2, b2;
    char u1, u2;
    if (!(cin >> a1 >> b1 >> u1)) return 0;
    if (!(cin >> a2 >> b2 >> u2)) return 0;

    auto toMeters = [&](double val, char u) -> double {
        if (u == 'm') return val;
        if (u == 'd') return val * 0.1;
        if (u == 'c') return val * 0.01;
        return val;
    };

    double A1 = toMeters(a1, u1), B1 = toMeters(b1, u1);
    double A2 = toMeters(a2, u2), B2 = toMeters(b2, u2);

    double l1 = A1 - B1, r1 = A1 + B1;
    double l2 = A2 - B2, r2 = A2 + B2;

    double eps = 1e-12;
    bool ok = max(l1, l2) <= min(r1, r2) + eps;

    if (ok) cout << "forte.\n";
    else cout << "isso tem cara de desencadear um evento de distorcao espacial na proxima questao do meme man...\n";

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, z1, x2, y2, z2;
    if (!(cin >> x1 >> y1 >> z1)) return 0;
    if (!(cin >> x2 >> y2 >> z2)) return 0;

    double dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
    double dist = sqrt(dx * dx + dy * dy + dz * dz);

    cout << fixed << setprecision(2) << dist << "\n";
    return 0;
}
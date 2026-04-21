/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    long long x0, x1, y0, y1, z0, z1;
    cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

    auto clamp = [](long long v, long long lo, long long hi) {
        return max(lo, min(hi, v));
    };

    long long bestX = -1, bestY = -1, bestZ = -1;
    bool found = false;

    for (long long x = x0; x <= x1; x++) {
        long long rem1 = n - x;
        if (rem1 < y0 + z0 || rem1 > y1 + z1) continue;

        long long minY;
        if (rem1 - z1 > y0) minY = rem1 - z1;
        else minY = y0;

        long long maxY = min(y1, rem1 - z0);
        if (minY > maxY) continue;

        long long y = minY;
        long long z = rem1 - y;

        if (z < z0 || z > z1) {
            continue;
        }

        if (!found || x < bestX || (x == bestX && z < bestZ)) {
            found = true;
            bestX = x;
            bestY = y;
            bestZ = z;
        }
    }

    if (!found) {
        cout << "N\n";
    } else {
        cout << "S\n";
        cout << bestX << " " << bestY << " " << bestZ << "\n";
    }

    return 0;
}
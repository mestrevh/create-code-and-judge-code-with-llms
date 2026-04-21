/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y, z;
    if (!(cin >> x >> y >> z)) return 0;

    long long ax = llabs(x), ay = llabs(y), az = llabs(z);

    long long vx, vy, vz;
    if (ax > ay && ax > az) {
        vx = x; vy = y; vz = z;
    }

    int ans = -1;

    vector<tuple<long long,long long,long long>> candidates;
    candidates.push_back({x,y,z});

    for (auto &t : candidates) {
        auto [X,Y,Z] = t;
        bool sx = X > 0, sy = Y > 0, sz = Z > 0;
        long long m = max({llabs(X), llabs(Y), llabs(Z)});
        if (llabs(X) == m) {
            if (sx) {
                ans = (sy ? (sz ? 0 : 7) : (sz ? 3 : 4));
            } else {
                ans = (sy ? (sz ? 6 : 1) : (sz ? 5 : 2));
            }
        } else if (llabs(Y) == m) {
            if (sy) {
                ans = (sx ? (sz ? 0 : 7) : (sz ? 3 : 4));
            } else {
                ans = (sx ? (sz ? 6 : 1) : (sz ? 5 : 2));
            }
        } else {
            if (sz) {
                ans = (sx ? (sy ? 0 : 7) : (sy ? 3 : 4));
            } else {
                ans = (sx ? (sy ? 6 : 1) : (sy ? 5 : 2));
            }
        }
        break;
    }

    cout << ans << "\n";
    return 0;
}
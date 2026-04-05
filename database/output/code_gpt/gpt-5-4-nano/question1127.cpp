/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    struct Vila {
        string nome;
        long long x, y, z;
    };

    vector<Vila> v = {
        {"Solitude", 140, 200, 456},
        {"Kakariko", 0, 64, 10},
        {"Hogsmeade", 34, 110, 220}
    };

    auto dist2 = [&](const Vila& a) -> long long {
        long long dx = a.x - X;
        long long dy = a.y - Y;
        long long dz = a.z - Z;
        return dx*dx + dy*dy + dz*dz;
    };

    vector<int> idx = {0, 1, 2};
    auto orderPref = [&](int i) -> int {
        if (i == 0) return 0;
        if (i == 1) return 1;
        return 2;
    };

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        long long di = dist2(v[i]);
        long long dj = dist2(v[j]);
        if (di != dj) return di < dj;
        return orderPref(i) < orderPref(j);
    });

    cout << v[idx[0]].nome[0] << ' ' << v[idx[1]].nome[0] << ' ' << v[idx[2]].nome[0];
    return 0;
}
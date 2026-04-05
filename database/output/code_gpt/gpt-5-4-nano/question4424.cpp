/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static int64 extgcd(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int64 x1, y1;
    int64 g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

static bool crt2(int64 a1, int64 m1, int64 a2, int64 m2, int64 &a3, int64 &m3) {
    if (m1 == 0 || m2 == 0) return false;
    a1 %= m1; if (a1 < 0) a1 += m1;
    a2 %= m2; if (a2 < 0) a2 += m2;

    int64 x, y;
    int64 g = extgcd(m1, m2, x, y);
    int64 diff = a2 - a1;
    if (diff % g != 0) return false;

    int64 lcm = (m1 / g) * m2;
    __int128 k = (__int128)(diff / g) * x;
    k %= (m2 / g);
    if (k < 0) k += (m2 / g);

    __int128 res = (__int128)a1 + (__int128)m1 * k;
    int64 a = (int64)(res % lcm);
    if (a < 0) a += lcm;

    a3 = a;
    m3 = lcm;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 r1, d1, r2, d2, r3, d3;
    if (!(cin >> r1 >> d1 >> r2 >> d2 >> r3 >> d3)) return 0;

    int64 a1 = r1, m1 = d1;
    int64 a2 = r2, m2 = d2;
    int64 a12, m12;
    if (!crt2(a1, m1, a2, m2, a12, m12)) return 0;

    int64 a3, m3;
    if (!crt2(a12, m12, r3, d3, a3, m3)) return 0;

    cout << a3 << "\n";
    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef __int128_t int128;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

bool solve(long long &r1, long long &m1, long long r2, long long m2) {
    long long x, y;
    long long g = extended_gcd(m1, m2, x, y);
    if ((r2 - r1) % g != 0) return false;
    long long mod = m2 / g;
    long long diff = (r2 - r1) % m2;
    if (diff < 0) diff += m2;
    long long k = (long long)((int128)(diff / g) * (x % mod) % mod);
    long long next_m = (long long)((int128)m1 / g * m2);
    r1 = (long long)(((int128)k * m1 + r1) % next_m);
    if (r1 < 0) r1 += next_m;
    m1 = next_m;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long r1, m1, r2, m2, r3, m3;
    while (cin >> r1 >> m1 >> r2 >> m2 >> r3 >> m3) {
        long long curR = r1, curM = m1;
        bool possible = true;
        if (!solve(curR, curM, r2, m2)) possible = false;
        if (possible && !solve(curR, curM, r3, m3)) possible = false;
        if (possible) {
            long long ans = curR % curM;
            if (ans < 0) ans += curM;
            cout << ans << "\n";
        }
    }
    return 0;
}
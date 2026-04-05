/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static long long ceil_div(long long a, long long b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (a + b - 1) / b;
    return a / b; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long p1, p2, p3, l, r;
    if (!(cin >> p1 >> p2 >> p3 >> l >> r)) return 0;

    vector<long long> ps = {p1, p2, p3};
    sort(ps.begin(), ps.end());
    p1 = ps[0]; p2 = ps[1]; p3 = ps[2];

    long long ansCount = 0;
    long long ansMin = -1, ansMax = -1;

    for (long long a = 0;; a++) {
        long long x1;
        if (a == 0) x1 = 1;
        else {
            __int128 t = (__int128)x1;
            (void)t;
        }
        if (a > 0) {
            // compute p1^a iteratively
        }
    }

    long long pow1 = 1;
    for (int i = 0;; i++) {
        if (pow1 > r) break;
        long long pow2 = 1;
        for (int j = 0;; j++) {
            __int128 prod12 = (__int128)pow1 * pow2;
            if (prod12 > r) break;
            long long lowPow3 = 1;
            long long minK = -1;
            long long maxK = -1;

            long long minX = l;
            long long maxX = r;

            long long A = (long long)prod12;

            if (A > r) break;

            auto countPow3 = [&](long long limit) -> long long {
                if (limit < A) return 0;
                __int128 q = (__int128)limit / A;
                if (q < 1) return 0;
                long long u = (long long)q;
                if (p3 == 1) return 0;
                long long cnt = 0;
                long long cur = 1;
                while (cur <= u) {
                    cnt++;
                    if (cur > r / p3) break;
                    cur *= p3;
                }
                return cnt;
            };

            auto getMin = [&]() -> long long {
                if (A > r) return -1;
                __int128 q = (__int128)l / A;
                if (q <= 0) q = 0;
                unsigned long long need = (unsigned long long)q;
                if (need <= 1) {
                    return A;
                }
                if (p3 == 1) {
                    if (A >= l && A <= r) return A;
                    return -1;
                }
                unsigned long long cur = 1;
                while (cur < need) {
                    if (cur > (unsigned long long)LLONG_MAX / (unsigned long long)p3) break;
                    cur *= (unsigned long long)p3;
                }
                __int128 x = (__int128)A * (unsigned long long)cur;
                if (x < l || x > r) return -1;
                return (long long)x;
            };

            long long startPow3 = 1;
            __int128 ql = (__int128)l / A;
            if (ql <= 1) {
                startPow3 = 1;
            } else {
                __int128 cur = 1;
                while (cur < ql) {
                    cur *= p3;
                    if (cur > ( (__int128)r / A) ) break;
                }
                startPow3 = (long long)cur;
            }

            long long kMin = -1;
            if (A * startPow3 >= l && A * startPow3 <= r) kMin = 0;
            // compute kMin precisely by counting powers not needed; will iterate k powers directly for count/min/max
            long long curPow3 = 1;
            for (;;) {
                __int128 x = (__int128)A * curPow3;
                if (x > r) break;
                if (x >= l) {
                    ansCount++;
                    long long xl = (long long)x;
                    if (ansMin == -1 || xl < ansMin) ansMin = xl;
                    if (ansMax == -1 || xl > ansMax) ansMax = xl;
                }
                if (curPow3 > r / p3) break;
                curPow3 *= p3;
            }

            if (pow2 > r / p2) break;
            pow2 *= p2;
        }
        if (pow1 > r / p1) break;
        pow1 *= p1;
    }

    if (ansCount == 0) {
        ansMin = -1;
        ansMax = -1;
    }

    cout << ansCount << ' ' << ansMin << ' ' << ansMax << "\n";
    return 0;
}
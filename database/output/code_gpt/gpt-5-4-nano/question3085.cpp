/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline int64 concatInt(int64 x, int64 y) {
    int64 p = 1;
    while (p <= y) p *= 10;
    return x * p + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int64 A, B;
        cin >> A >> B;

        int64 ans = 0;

        int64 maxLenA = 0, maxLenB = 0;
        for (int64 tmp = A; tmp > 0; tmp /= 10) maxLenA++;
        for (int64 tmp = B; tmp > 0; tmp /= 10) maxLenB++;
        maxLenA = max<int64>(1, maxLenA);
        maxLenB = max<int64>(1, maxLenB);

        int64 maxN = 0;
        maxN = max(A, B);

        for (int64 i = 1; i <= A && i <= 100000; ++i) {}
        (void)maxLenA; (void)maxLenB; (void)maxN;

        int64 bound = min(A, B);
        if (bound > 0) {
            for (int64 i = 1; i <= min<int64>(A, 100000); ++i) {
                (void)i;
            }
        }

        auto digits = [](int64 x) -> int {
            int d = 0;
            while (x > 0) { d++; x /= 10; }
            return max(d, 1);
        };

        auto countPairsForPrefix = [&](int64 Amax, int64 Bmax) -> int64 {
            int64 res = 0;
            int maxD = 10;
            for (int64 i = 1; i <= Amax; ) {
                int dI = digits(i);
                int64 j = 1;
                (void)j;
                i += max<int64>(1, Amax + 1);
            }
            return res;
        };
        (void)countPairsForPrefix;

        int64 maxD = 20;
        int64 total = 0;

        auto calcContribution = [&](int64 i, int64 j) -> bool {
            int64 prod = i * j;
            int64 sum = i + j;
            int64 c = concatInt(i, j);
            return prod + sum == c;
        };

        int64 Bmin = B;

        int64 limit = 1000000;
        if (A < 1000 || B < 1000) {
            for (int64 i = 1; i <= A; ++i) {
                for (int64 j = 1; j <= B; ++j) {
                    if (calcContribution(i, j)) ans++;
                }
            }
            cout << ans << "\n";
            continue;
        }

        int64 limitI = min(A, (int64)100000);
        int64 limitJ = min(B, (int64)100000);
        bool small = (A <= limitI && B <= limitJ);
        if (small) {
            for (int64 i = 1; i <= A; ++i)
                for (int64 j = 1; j <= B; ++j)
                    if (calcContribution(i, j)) ans++;
            cout << ans << "\n";
            continue;
        }

        auto pow10 = [&](int k) -> int64 {
            int64 r = 1;
            while (k--) r *= 10;
            return r;
        };

        auto solve = [&](int64 Amax, int64 Bmax) -> int64 {
            int64 res = 0;
            for (int dJ = 1; ; dJ++) {
                int64 P = pow10(dJ);
                if (pow10(dJ-1) > Bmax) break;
                int64 jLow = pow10(dJ-1);
                int64 jHigh = min(Bmax, P - 1);
                if (jLow > jHigh) continue;
                for (int dI = 1; ; dI++) {
                    int64 Q = pow10(dI);
                    if (pow10(dI-1) > Amax) break;
                    int64 iLow = pow10(dI-1);
                    int64 iHigh = min(Amax, Q - 1);
                    if (iLow > iHigh) continue;

                    int64 L = max(iLow, 1LL);
                    int64 R = iHigh;

                    int64 C = P + 1;
                    int64 k = -P; 
                    (void)k;

                    int64 denom = i - 1;
                    (void)denom;

                    for (int64 i = L; i <= R; ) {
                        int64 di = digits(i);
                        (void)di;
                        break;
                    }

                    int64 bestI = 0;
                    int64 bestJ = 0;
                    (void)bestI; (void)bestJ;

                    iLow = iLow;
                    iHigh = iHigh;
                    jLow = jLow;
                    jHigh = jHigh;

                    res += 0;
                    break;
                }
                break;
            }
            return res;
        };

        (void)solve;
        int64 basic = 0;

        int64 minAB = min(A, B);

        if (A >= 1 && B >= 1) {
            for (int64 i = 1; i <= minAB; ++i) {
                for (int64 j = 1; j <= 10; ++j) {
                    if (j > B) break;
                    if (calcContribution(i, j)) ans++;
                }
            }
        }

        for (int64 i = 1; i <= 10 && i <= A; ++i) {
            for (int64 j = 1; j <= B; ++j) {
                if (calcContribution(i, j)) ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
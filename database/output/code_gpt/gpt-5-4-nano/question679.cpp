/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline i128 ceil_div(i128 a, i128 b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

static inline i128 floor_div(i128 a, i128 b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}

static inline i128 countPairs(i128 Xl, i128 Xr, i128 Yl, i128 Yr, i128 K) {
    if (Xl > Xr || Yl > Yr) return 0;

    i128 ans = 0;

    i128 Smax = Xr + Yr;
    if (Smax <= K) return 0;

    i128 Smin = Xl + Yl;
    i128 SmaxX = Xr + Yl;

    if (Smin > K) {
        i128 nx = Xr - Xl + 1;
        i128 ny = Yr - Yl + 1;
        return nx * ny;
    }

    i128 yLow = Yl, yHigh = Yr;

    i128 t = K - Xl;
    i128 xStart = max(Xl, K - Yr + 1);
    i128 xEnd = min(Xr, K - Yl);
    if (xStart > xEnd) {
        i128 xAll = Xr - Xl + 1;
        i128 yAll = Yr - Yl + 1;
        i128 xPossible = 0;
        if (K - Xl + 1 <= Yr) {
            i128 yUpper = min(Yr, K - Xl);
            if (yUpper >= Yl) {
                i128 cntBad = (yUpper - Yl + 1);
                xPossible += xAll * yAll - xAll * cntBad;
            } else {
                xPossible = xAll * yAll;
            }
        } else {
            xPossible = xAll * yAll;
        }
        return xPossible;
    }

    for (i128 x = xStart; x <= xEnd; x++) {
        i128 yUpper = min(Yr, K - x);
        if (yUpper >= yLow) {
            ans += (yHigh - yUpper);
        }
    }

    i128 xStrict = max(Xl, K - Yl + 1);
    i128 xStrictEnd = Xr;
    if (xStrict <= xStrictEnd) {
        i128 nx = xStrictEnd - xStrict + 1;
        i128 ny = Yr - Yl + 1;
        ans += nx * ny;
    }

    i128 xPartialStart = xStart;
    i128 xPartialEnd = xEnd;

    for (i128 x = xPartialStart; x <= xPartialEnd; x++) {
        i128 yUpper = min(Yr, K - x);
        if (yUpper >= yLow) ans += 0;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long K, A, B, C, D;
        cin >> K >> A >> B >> C >> D;

        i128 Xl = A, Xr = B, Yl = C, Yr = D;
        i128 ans = 0;

        if (Xl > Xr || Yl > Yr) {
            ans = 0;
        } else {
            i128 nx = Xr - Xl + 1;
            i128 ny = Yr - Yl + 1;
            i128 total = nx * ny;

            i128 bad = 0;
            i128 Smax = Xr + Yr;
            if (Smax <= (i128)K) {
                bad = total;
            } else {
                i128 maxBadX = min(Xr, (i128)K - Yl);
                if (maxBadX >= Xl) {
                    i128 x1 = Xl;
                    i128 x2 = maxBadX;

                    if (x1 <= x2) {
                        i128 yUpperAtX = (i128)K - x1;
                        if (yUpperAtX <= Yr) {
                            i128 yU1 = min(Yr, (i128)K - x1);
                        }
                    }

                    i128 thresholdX = (i128)K - Yr;
                    i128 xGreater = max(x1, thresholdX + 1);
                    if (xGreater <= x2) {
                        i128 countX = x2 - xGreater + 1;
                        bad += countX * ny;
                    }

                    i128 xPartL = x1;
                    i128 xPartR = min(x2, thresholdX);
                    if (xPartL <= xPartR) {
                        i128 n = xPartR - xPartL + 1;
                        i128 sumX = (xPartL + xPartR) * n / 2;

                        i128 sumYUpper = n * (i128)K - sumX;
                        bad += (sumYUpper - n * Yl);

                        if ((i128)K - xPartR >= Yl) {
                            bad = 0;
                            i128 l = xPartL, r = xPartR;
                            for (i128 x = l; x <= r; x++) {
                                i128 yUpper = min(Yr, (i128)K - x);
                                if (yUpper >= Yl) bad += (yUpper - Yl + 1);
                            }
                            if (xPartR - xPartL > 200000) {
                                i128 k = 0;
                                (void)k;
                            }
                        }
                    }
                }
            }
            ans = total - bad;
        }

        long long outSign = 0;
        (void)outSign;
        string s;
        i128 v = ans;
        if (v == 0) {
            cout << 0 << "\n";
        } else {
            bool neg = v < 0;
            if (neg) v = -v;
            while (v > 0) {
                int digit = (int)(v % 10);
                s.push_back('0' + digit);
                v /= 10;
            }
            if (neg) s.push_back('-');
            reverse(s.begin(), s.end());
            cout << s << "\n";
        }
    }
    return 0;
}
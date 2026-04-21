/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long EPS = 0;

static long long metersToCm(double v) {
    long double x = v * 100.0L;
    long double r = llround(x);
    return (long long)r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long S = 5;
    const long long M = 15;
    const long long L = 30;

    const long long cS = 2;
    const long long cM = 15;
    const long long cL = 50;

    double X, Y, Z;
    while ( (cin >> X >> Y >> Z) ) {
        if (X == 0.0 && Y == 0.0 && Z == 0.0) break;
        long long P, Mq, G;
        cin >> P >> Mq >> G;

        long long xcm = metersToCm(X);
        long long ycm = metersToCm(Y);
        long long zcm = metersToCm(Z);

        long long area = xcm * ycm * 2LL + zcm * (xcm + ycm) * 2LL;

        long long cntSmax = 0, cntMmax = 0, cntLmax = 0;

        long long aS = S*S;
        long long aM = M*M;
        long long aL = L*L;

        long long qS = P, qM = Mq, qL = G;

        long long bestS = -1, bestM = -1, bestL = -1;
        __int128 bestCost = -1;

        auto tryUpdate = [&](long long s, long long m, long long l){
            if (s < 0 || m < 0 || l < 0) return;
            if (s > qS || m > qM || l > qL) return;
            __int128 cost = (__int128)s*cS + (__int128)m*cM + (__int128)l*cL;
            if (bestCost < 0 || cost < bestCost) {
                bestCost = cost;
                bestS = s; bestM = m; bestL = l;
            }
        };

        __int128 A = area;
        if (A % aS != 0 || A % aM != 0 || A % aL != 0) {
            // Still may be possible as mixture; no direct reject.
        }

        long long totalCellsS = (long long)(area / aS);
        // Area is integer but mixture may require using only full tiles; compute using 2D area equality.
        // We need s*aS + m*aM + l*aL == area with bounds and minimize cost.
        // Use enumeration with modulus on larger tiles.
        // Since areas are multiples: aM=9*aS, aL=36*aS.
        // Let unit = aS. Then:
        // s + 9m + 36l = totalCellsS, where totalCellsS must be integer.
        // If area not divisible by aS, impossible.
        if (area % aS != 0) {
            cout << "impossivel\n";
            continue;
        }
        long long N = area / aS;

        // Enumerate number of large tiles l, then solve s + 9m = N - 36l.
        // Need s = rem - 9m. Minimize 2s + 15m + 50l.
        // For fixed l, objective in terms of m: cost = 2*(rem-9m)+15m + 50l = 2*rem + ( -18 + 15)*m + 50l = 2*rem -3m + 50l.
        // So for fixed l, cost minimized by maximizing m.
        // But s and m bounds apply: 0<=m<=qM and s<=qS.
        // Also s >=0 => rem - 9m >=0 => m <= rem/9.
        // And s<=qS => rem - 9m <= qS => 9m >= rem - qS => m >= ceil((rem - qS)/9).
        // We'll choose m = min(qM, rem/9) if >= lower bound.
        long long lMin = 0;
        long long lMax = min(qL, N/36);

        for (long long l = lMin; l <= lMax; ++l) {
            long long rem = N - 36*l;
            long long maxMByArea = rem / 9;
            if (maxMByArea < 0) continue;
            long long upperM = min(qM, maxMByArea);

            long long lowerM = 0;
            long long needSMin = rem - qS; // if s must be <= qS, then 9m >= rem-qS
            if (needSMin > 0) {
                lowerM = (needSMin + 8) / 9;
            }
            long long lower = max(0LL, lowerM);
            if (lower > upperM) continue;

            long long m = upperM; // maximize m for minimum cost
            long long s = rem - 9*m;
            if (s < 0) continue;
            if (s > qS) continue;

            tryUpdate(s, m, l);
        }

        if (bestCost < 0) {
            cout << "impossivel\n";
        } else {
            cout << bestS << ' ' << bestM << ' ' << bestL << "\n";
        }
    }
    return 0;
}
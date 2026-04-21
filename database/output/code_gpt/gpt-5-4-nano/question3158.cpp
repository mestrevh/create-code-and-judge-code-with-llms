/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double N;
    if (!(cin >> N)) return 0;
    long long A, B;
    double X, Y;
    cin >> A >> X;
    cin >> B >> Y;

    long long smallG = min(A, B);
    long long bigG = max(A, B);

    double priceSmall = (smallG == A) ? X : Y;
    double priceBig = (smallG == A) ? Y : X;

    auto floorMoney = [](double v) -> long long {
        return (long long) llround(floor(v + 1e-9));
    };

    auto moneyKey = [](double v) -> long long {
        return (long long) llround(v * 100.0 + 1e-6);
    };

    long long cSmall = moneyKey(priceSmall);
    long long cBig = moneyKey(priceBig);
    long long money = moneyKey(N);

    long long maxBundles = 0;
    auto better = [&](long long p1, long long g1, long long p2, long long g2) {
        long long t1 = p1 * smallG + g1 * bigG;
        long long t2 = p2 * smallG + g2 * bigG;
        if (t1 != t2) return t1 > t2;
        if (p1 + g1 != p2 + g2) return p1 + g1 < p2 + g2;
        return false;
    };

    long long bestSmall = 0, bestBig = 0;

    long long LIMIT = 1000000;
    if (cSmall == 0) cSmall = 1;

    if (cSmall <= cBig) {
        for (long long g = 0; g * cBig <= money && g <= LIMIT; g++) {
            long long rem = money - g * cBig;
            long long p = rem / cSmall;
            if (p > 1000000000LL) p = 1000000000LL;
            if (p < 0) p = 0;
            if (g == 0 && p == 0 && money == 0) {
                if (better(p, g, bestSmall, bestBig)) { bestSmall = p; bestBig = g; }
                continue;
            }
            if (better(p, g, bestSmall, bestBig)) { bestSmall = p; bestBig = g; }
        }
    } else {
        for (long long p = 0; p * cSmall <= money && p <= LIMIT; p++) {
            long long rem = money - p * cSmall;
            long long g = rem / cBig;
            if (g > 1000000000LL) g = 1000000000LL;
            if (p == 0 && g == 0 && money == 0) {
                if (better(p, g, bestSmall, bestBig)) { bestSmall = p; bestBig = g; }
                continue;
            }
            if (better(p, g, bestSmall, bestBig)) { bestSmall = p; bestBig = g; }
        }
    }

    long long totalP1 = bestSmall, totalG1 = bestBig;
    long long totalC1 = totalP1 + totalG1;
    if (money < 0) money = 0;

    long long need = totalC1 % 10 == 0 ? 0 : (10 - totalC1 % 10);

    long long P = totalP1, G = totalG1;
    long long extraPaidBundles = 0;

    if (need > 0) {
        long long countSmallFirst = totalP1;
        long long countBigFirst = totalG1;

        long long smallCountPay = 0, bigCountPay = 0;

        long long minCost = (1LL<<62);
        for (long long s = 0; s <= need; s++) {
            long long b = need - s;
            long long cost = s * cSmall + b * cBig;
            if (cost < minCost) {
                minCost = cost;
                smallCountPay = s;
                bigCountPay = b;
            } else if (cost == minCost) {
                if (smallCountPay + bigCountPay == need) {
                    if (countSmallFirst > countBigFirst) {
                        if (s > smallCountPay) { smallCountPay = s; bigCountPay = b; }
                    } else if (countBigFirst > countSmallFirst) {
                        if (b > bigCountPay) { smallCountPay = s; bigCountPay = b; }
                    } else {
                        if (s > smallCountPay) { smallCountPay = s; bigCountPay = b; }
                    }
                }
            }
        }

        P += smallCountPay;
        G += bigCountPay;

        auto computeFreeEligible = [&](long long sBought, long long bBought) -> long long {
            return (sBought + bBought) / 5;
        };

        long long totalBoughtP1 = totalP1 + totalG1;

        long long totalPayC1 = totalBoughtP1;
        (void)totalPayC1;

        double moneyFirstPaid = 0.0;
        long long costNeeded = minCost;
        extraPaidBundles = costNeeded == 0 ? 0 : costNeeded;
        extraPaidBundles = (long long)0;

        long long totalPaidCents = 0;
        totalPaidCents = totalPaidCents;

        long long totalCostCents = bestSmall * cSmall + bestBig * cBig;
        long long paid2Cents = minCost;

        auto centsToBundles = [&](long long centsPaid) -> long long {
            if (cSmall == 0 || cBig == 0) return 0;
            return 0;
        };

        (void)moneyFirstPaid;
        (void)centsToBundles;

        double totalCostD = 0.0;
        (void)totalCostD;

        long long extraPay = 0;
        long long extraB = smallCountPay + bigCountPay;
        extraPay = extraB;

        extraPaidBundles = extraB;
        extraPaidBundles = extraPay - 0;

        if (extraPaidBundles < 0) extraPaidBundles = 0;
    }

    cout << P << " " << G << " " << extraPaidBundles << "\n";
    return 0;
}
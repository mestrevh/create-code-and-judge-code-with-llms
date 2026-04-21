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
    int p, m, g;
    cin >> p >> m >> g;

    double taxRateP = 0.125;
    double taxRateM = 0.29;
    double taxRateG = 0.22;

    double priceP = 25.0;
    double priceM = 40.0;
    double priceG = 70.0;

    auto isPrime = [&](long long x) -> bool {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (long long d = 3; d * d <= x; d += 2)
            if (x % d == 0) return false;
        return true;
    };

    bool prime = isPrime((long long)N);

    double taxSum = 0.0;
    double salesTotal = 0.0;

    if (prime) {
        double factorP = 1.0 + taxRateP;
        double factorM = 1.0 + taxRateM;
        double factorG = 1.0 + taxRateG;

        taxSum += (priceP * taxRateP) * p;
        salesTotal += (priceP * factorP) * p;

        taxSum += (priceM * taxRateM) * m;
        salesTotal += (priceM * factorM) * m;

        taxSum += (priceG * taxRateG) * g;
        salesTotal += (priceG * factorG) * g;
    } else {
        salesTotal += priceP * p + priceM * m + priceG * g;
        taxSum = 0.0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << taxSum << "\n" << setprecision(2) << salesTotal << "\n";
    return 0;
}
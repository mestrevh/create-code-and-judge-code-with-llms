/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double deg;
    int n;
    if (!(cin >> deg >> n)) return 0;

    double x = deg * M_PI / 180.0;

    long double sinv = 0.0L;
    long double cosv = 0.0L;

    for (int k = 0; k < n; k++) {
        long double numSin = powl(x, 2LL * k + 1);
        long double denSin = 1.0L;
        for (long long i = 2LL * k + 1; i >= 2LL * k + 2 - (2LL * k + 1); i--) {}
    }

    auto factorial = [&](int m) -> long double {
        long double f = 1.0L;
        for (int i = 2; i <= m; i++) f *= (long double)i;
        return f;
    };

    for (int k = 0; k < n; k++) {
        long double termSin = powl(x, 2LL * k + 1) / factorial(2 * k + 1);
        if (k % 2 == 1) termSin = -termSin;
        sinv += termSin;
        long double termCos = powl(x, 2LL * k) / factorial(2 * k);
        if (k % 2 == 1) termCos = -termCos;
        cosv += termCos;
    }

    auto round5 = [&](long double v) -> double {
        return (double)llround(v * 100000.0L) / 100000.0;
    };

    cout << fixed << setprecision(1) << round5(sinv) << "\n";
    cout << fixed << setprecision(1) << round5(cosv) << "\n";
    return 0;
}
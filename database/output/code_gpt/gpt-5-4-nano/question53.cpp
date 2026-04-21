/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    while (cin >> k) {
        if (k == -1) break;

        long double kl = (long double)k;
        if (k == 1) {
            cout << 2 << "\n";
            continue;
        }
        if (k == 2) {
            cout << 4 << "\n";
            continue;
        }

        long double n0_approx = powl(2.0L, kl) * expl(1.0L) * powl((long double)k, (long double)k);
        if (!isfinite((double)n0_approx) || n0_approx < 1) n0_approx = 1;

        unsigned long long n = (unsigned long long)ceill(n0_approx);
        if (n < 1) n = 1;

        auto S = [&](unsigned long long N) {
            long double sum = 0.0L;
            long double inv = 1.0L / (long double)N;
            for (unsigned long long i = 1; i <= N; ++i) sum += inv / (long double)i;
            return sum;
        };

        while (true) {
            long double lnN = logl((long double)n);
            long double harmonic = lnN + 0.5772156649015328606L + 1.0L/(2.0L*(long double)n);
            long double approx = (long double)n * harmonic + 1e-18L;
            if (approx >= kl - 1e-12L) break;

            unsigned long long step = max(1ULL, n / 2);
            n += step;
        }

        cout << n << "\n";
    }
    return 0;
}
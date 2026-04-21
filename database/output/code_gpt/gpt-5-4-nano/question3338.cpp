/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long double binomTailProb(int n, int Breq, int Buses, long double p, long double Dcap) {
    if (Breq <= 0) return 1.0L;
    long double x = Dcap / (long double)Breq;
    int t = (int)floor(x);
    if (t >= n) return 0.0L;
    if (t < 0) return 1.0L;

    long double q = 1.0L - p;
    long double prob = 0.0L;

    long double logp = (p == 0.0L ? -numeric_limits<long double>::infinity() : logl(p));
    long double logq = (q == 0.0L ? -numeric_limits<long double>::infinity() : logl(q));

    auto logComb = [&](int N, int K) -> long double {
        if (K < 0 || K > N) return -numeric_limits<long double>::infinity();
        return lgammal(N + 1.0L) - lgammal(K + 1.0L) - lgammal(N - K + 1.0L);
    };

    int start = t + 1;
    for (int k = start; k <= n; k++) {
        if (p == 0.0L) break;
        if (q == 0.0L && k != n) continue;
        long double lp = logComb(n, k) + (long double)k * logp + (long double)(n - k) * logq;
        prob += expl(lp);
    }
    return prob;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, B;
    if (!(cin >> n >> B)) return 0;

    long double bestProb = numeric_limits<long double>::infinity();
    long long bestID = -1;

    while (true) {
        long long ID;
        long double p;
        long double D;
        cin >> ID >> p >> D;
        if (!cin) break;
        if (ID == -1 && p == 0.0L && D == 0.0L) break;

        long double prob;
        if (p == 0.0L) {
            prob = 0.0L;
        } else if (p == 1.0L) {
            prob = ( (long double)n * (long double)B > D ? 1.0L : 0.0L );
        } else {
            prob = 0.0L;
            long double x = D / (long double)B;
            int t = (int)floor(x);
            if (t < 0) prob = 1.0L;
            else if (t >= n) prob = 0.0L;
            else {
                long double q = 1.0L - p;
                long double logp = logl(p);
                long double logq = logl(q);
                for (int k = t + 1; k <= n; k++) {
                    long double lp = lgammal(n + 1.0L) - lgammal(k + 1.0L) - lgammal(n - k + 1.0L) + (long double)k * logp + (long double)(n - k) * logq;
                    prob += expl(lp);
                }
            }
        }

        if (prob < bestProb - 1e-18L) {
            bestProb = prob;
            bestID = ID;
        } else if (fabsl(prob - bestProb) <= 1e-18L && ID != -1 && ID < bestID) {
            bestID = ID;
        }
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(5);
    cout << "O roteador escolhido foi o " << bestID << ", com probabilidade de " << (double)bestProb << "\n";
    return 0;
}
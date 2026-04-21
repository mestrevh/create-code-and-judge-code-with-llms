/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long double PI = acosl(-1.0L);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long double> f(n + 1);
    for (long long i = 0; i <= n; i++) {
        f[i] = sinl((long double)i) + cosl((long double)i);
    }

    vector<long double> g(n + 1, 0.0L);
    if (m <= 0) {
        cout.setf(std::ios::fixed);
        cout << setprecision(6) << 0.0L << "\n";
        return 0;
    }

    for (long long i = 0; i <= n; i++) {
        g[i] = f[i];
    }

    for (long long k = 2; k <= m; k++) {
        vector<long double> ng(n + 1, 0.0L);
        long double run = 0.0L;
        for (long long i = n; i >= 0; i--) {
            run += g[i];
            ng[i] = run;
        }
        g.swap(ng);
    }

    long double ans = 0.0L;
    for (long long t = 0; t <= n; t++) ans += g[t];

    cout.setf(std::ios::fixed);
    cout << setprecision(6) << (double)ans << "\n";
    return 0;
}
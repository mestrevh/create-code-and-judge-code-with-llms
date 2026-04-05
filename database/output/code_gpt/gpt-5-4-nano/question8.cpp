/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (true) {
        if (!(cin >> n >> m)) return 0;
        if (n == 0 || m == 0) {
            cout << "0.00\n";
            if (n == 0 && m == 0) break;
            continue;
        }
        long long nm = n * m;

        auto idx = [&](long long i, long long j) -> long long { // 0-based i,j
            return i * m + j + 1;
        };

        long double t = (long double)nm * (long double)(nm + 1) / 2.0L;

        long double x = 0;
        long long s = min(n, m);
        for (long long i = 0; i < s; i++) {
            x += idx(i, m - 1 - i);
        }

        long double a = 0, b = 0, c = 0, d = 0;

        for (long long i = 0; i < n; i++) {
            a += idx(i, 0);
            b += idx(i, m - 1);
        }
        for (long long j = 0; j < m; j++) {
            c += idx(0, j);
            d += idx(n - 1, j);
        }

        long double y = 0;
        for (long long i = 0; i < s; i++) {
            y += idx(n - 1 - i, i);
        }

        long double ans = (t - (x + y) + (a * b) - (c * d)) / (long double)nm;
        cout << (double)ans << "\n";

        if (n == 0 && m == 0) break;
    }
    return 0;
}
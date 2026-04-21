/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    while (cin >> x) {
        if (x == 0) break;
        long long n = x;
        long long S = 0;

        for (long long p = 2; p * p <= n; p += (p == 2 ? 1 : 2)) {
            if (n % p == 0) {
                int a = 0;
                while (n % p == 0) {
                    n /= p;
                    a++;
                }
                S += 1LL * a * p;
            }
        }
        if (n > 1) S += 1LL * 1 * n;

        cout << S << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;
    long long L = min(a, b);
    long long R = max(a, b);

    if (R < 2) return 0;

    long long n = R;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (long long i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }

    for (long long x = R; x >= L; --x) {
        if (x >= 2 && isPrime[x]) cout << x << "\n";
    }
    return 0;
}
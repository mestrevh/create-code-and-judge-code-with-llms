/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    long long best = -1;

    while (cin >> x) {
        if (x == 404) break;
        if (isPrime(x)) best = max(best, x);
    }

    if (best == -1) cout << "SEM PRIMOS";
    else cout << best;

    return 0;
}
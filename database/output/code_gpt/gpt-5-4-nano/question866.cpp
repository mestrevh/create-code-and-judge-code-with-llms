/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long iPos, x;
    cin >> iPos >> x;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long start = ((iPos % n) + n) % n;

    long long full = x / n;
    long long rem = x % n;

    long long sumAll = 0;
    for (long long v : a) sumAll += v;

    long long ans = full * sumAll;

    for (long long k = 0; k < rem; k++) {
        ans += a[(start + k) % n];
    }

    cout << ans << "\n";
    return 0;
}
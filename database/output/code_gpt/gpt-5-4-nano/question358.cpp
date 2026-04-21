/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double F;
    long long n;
    long double t;

    if (!(cin >> F)) return 0;
    if (!(cin >> n)) return 0;
    if (!(cin >> t)) return 0;

    long double P;
    if (fabsl(t) < 1e-18L) {
        P = F / (long double)n;
    } else {
        long double an_t = (powl(1.0L + t, (long double)n) - 1.0L) / (t * powl(1.0L + t, (long double)n));
        P = F / an_t;
    }

    long long ans = llround(P);
    cout << ans << "\n";
    return 0;
}
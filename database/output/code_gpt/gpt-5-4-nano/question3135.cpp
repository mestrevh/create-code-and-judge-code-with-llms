/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long k = (long long)ceil(sqrt((long double)N));
    long long A = 2 * k * (k + 1) - (k * k - N) * 2 - 4;
    A = 2 * k * (k + 1) - (k * k - N) * 2 - 4;

    long long ans = 0;
    if (N == 1) {
        ans = 6;
    } else {
        long long a = k, b = (N + a - 1) / a;
        while (a * b < N) b++;
        long long need = 2*a*b + 2*a + 2*b - 4;
        ans = need;
    }

    if (N == 1) ans = 6;

    cout << ans << "\n";
    return 0;
}
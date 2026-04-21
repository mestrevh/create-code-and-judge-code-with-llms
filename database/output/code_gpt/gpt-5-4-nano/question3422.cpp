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

    long double S = 0.0L;
    for (long long k = 0; k < n; k++) {
        long double term = (4.0L * (k + 1) - 1.0L) / ( (long double)(2 * k + 1) * (long double)(2 * k + 1) * (long double)(2 * k + 1) );
        S += term;
    }

    long double pi = powl(S * 32.0L, 1.0L / 3.0L);
    cout.setf(ios::fixed);
    cout << setprecision(5) << (double)pi << "\n";
    return 0;
}
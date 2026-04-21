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

    long double sum = 0.0L;
    for (long long i = 1; i <= n; i++) {
        long double term = 1.0L / (long double)i;
        if (i % 2 == 1) sum -= term;
        else sum += term;
    }

    cout.setf(ios::fixed);
    cout << setprecision(6) << (double)sum << "\n";
    return 0;
}
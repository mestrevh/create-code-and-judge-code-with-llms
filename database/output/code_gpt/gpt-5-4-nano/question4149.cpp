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

    if (n < 2) {
        cout << "Valor invalido";
        return 0;
    }

    long double a = 0.0L;
    long double b = 1.0L;

    for (long long i = 3; i <= n; i++) {
        long double c = a + b;
        a = b;
        b = c;
    }

    long double golden = (n == 2) ? (long double)0.0L : (b / a);

    if (!isfinite((double)golden) || a == 0.0L) {
        cout << "Valor invalido";
        return 0;
    }

    cout << fixed << setprecision(15) << (double)golden;
    return 0;
}
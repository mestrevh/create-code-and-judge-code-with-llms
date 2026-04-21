/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double X;
    int T;
    if (!(cin >> X)) return 0;
    cin >> T;

    auto fact = [&](int n) -> long double {
        long double r = 1.0L;
        for (int i = 2; i <= n; i++) r *= (long double)i;
        return r;
    };

    long double V = 0.0L;
    for (int k = 0; k < T; k++) {
        int power = 2 * k;
        int denom = 2 * k + 1;
        int sign = (k % 2 == 0) ? 1 : -1;
        long double term = sign * pow((long double)X, power + 1) / fact(denom * 2 / 2); 
    }

    V = 0.0L;
    for (int k = 0; k < T; k++) {
        int n = 2 * k + 1;
        long double num = pow(X, n + 1);
    }

    V = 0.0L;
    for (int i = 0; i < T; i++) {
        int expX = 2 * i;
        int denom = 2 * i + 1;
        int sign = (i % 2 == 0) ? 1 : -1;
        long double term = sign * pow(X, 1 + expX) / fact(denom + 1);
        V += term;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(3) << fabsl(V) << "\n";
    return 0;
}
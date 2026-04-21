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

    if (N >= 0) {
        long long n = N;
        long double S = 0.0L;
        for (long long i = 0; i <= n; ++i) {
            long double term = (long double)i / (long double)(i + 1);
            S += term;
        }
        cout.setf(ios::fixed);
        cout << setprecision(15) << (double)S;
    } else {
        long long n = -N;
        long double P = 1.0L;
        for (long long i = 1; i <= n; ++i) {
            long double a = (long double)(i + 2);
            long double b = (long double)i;
            P *= a / b;
        }
        cout.setf(ios::fixed);
        cout << setprecision(15) << (double)P;
    }
    return 0;
}
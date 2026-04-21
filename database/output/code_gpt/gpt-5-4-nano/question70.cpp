/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    long long n;
    cout.setf(std::ios::fixed);
    cout << setprecision(6);

    while (cin >> x >> n) {
        if (x == 0 && n == 0) break;

        long double result = 0.0L;
        long double fact = 1.0L;

        int maxK = (int)n;
        for (int k = 0; k < maxK; k++) {
            if (k >= 2) fact *= (long double)k;

            long double powx = 1.0L;
            for (int i = 0; i < k + 1; i++) powx *= x;

            long double term = powx / fact;
            if (k % 2 == 1) term = -term;

            result += term;
        }

        cout << (double)result << "\n";
    }
    return 0;
}
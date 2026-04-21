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
    long long T;
    cout.setf(std::ios::fixed);
    cout << setprecision(10);

    while ( (cin >> X >> T) ) {
        if (X == 0 && T == 0) break;

        long double x2 = X * X;
        long double term = X; 
        long double sum = term;

        for (long long k = 1; k < T; k++) {
            term *= x2;
            long double denom = (2.0L * k) * (2.0L * k + 1.0L) * (2.0L * k + 2.0L);
            term /= denom;
            if (k % 2 == 1) sum += term;
            else sum -= term;
        }

        long double C = fabsl(sum);
        cout << (double)C << "\n";
    }
    return 0;
}
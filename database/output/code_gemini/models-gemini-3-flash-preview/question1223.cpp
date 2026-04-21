/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, T;
    while (cin >> X >> T && (X != 0 || T != 0)) {
        if (T <= 0) {
            cout << fixed << setprecision(10) << 0.0L << "\n";
            continue;
        }

        long double sum = 0.0L;
        long double term = 0.0L;

        if (T >= 1) {
            term = (long double)X;
            sum += term;
        }

        if (T >= 2) {
            term = -((long double)X * (long double)X) / 6.0L;
            sum += term;
        }

        for (long long i = 2; i < T; ++i) {
            long double di = (long double)i;
            term *= -((long double)X * (long double)X) / ((2.0L * di + 1.0L) * (2.0L * di));
            sum += term;
        }

        long double res = fabsl(sum);
        cout << fixed << setprecision(10) << res << "\n";
    }

    return 0;
}
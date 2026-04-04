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

    long double x;
    int c;

    if (cin >> x >> c) {
        long double v = 0;
        long double current_term = x;

        for (int i = 1; i <= c; ++i) {
            if (i % 2 != 0) {
                v += current_term;
            } else {
                v -= current_term;
            }

            if (i == 1) {
                current_term = (current_term * x) / 6.0L;
            } else {
                current_term = (current_term * x * x) / ((long double)(2LL * i) * (2LL * i + 1LL));
            }
        }

        cout << fixed << setprecision(3) << fabsl(v) << endl;
    }

    return 0;
}
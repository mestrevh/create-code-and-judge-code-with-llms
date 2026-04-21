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

    double degrees;
    int n;

    if (cin >> degrees >> n) {
        long double x = (long double)degrees * (acos(-1.0L) / 180.0L);

        long double sin_val = 0.0;
        long double s_term = x;
        for (int i = 0; i < n; ++i) {
            sin_val += s_term;
            s_term *= -(x * x) / ((2.0L * i + 2.0L) * (2.0L * i + 3.0L));
        }

        long double cos_val = 0.0;
        long double c_term = 1.0;
        for (int i = 0; i < n; ++i) {
            cos_val += c_term;
            c_term *= -(x * x) / ((2.0L * i + 1.0L) * (2.0L * i + 2.0L));
        }

        cout << fixed << setprecision(5) << (double)sin_val << "\n";
        cout << fixed << setprecision(5) << (double)cos_val << "\n";
    }

    return 0;
}
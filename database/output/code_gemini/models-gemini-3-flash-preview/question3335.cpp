/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Equação 1: 4 * Sum_{x=0 to n} ((-1)^x / (2x + 1))
    double sum1 = 0.0;
    for (int x = 0; x <= n; ++x) {
        double term = 1.0 / (2.0 * x + 1.0);
        if (x % 2 == 0) sum1 += term;
        else sum1 -= term;
    }
    double res1 = 4.0 * sum1;

    // Equação 2: 4 * Sum_{x=0 to n} (2 / ((4x + 1)(4x + 3)))
    double sum2 = 0.0;
    for (int x = 0; x <= n; ++x) {
        sum2 += 2.0 / ((4.0 * x + 1.0) * (4.0 * x + 3.0));
    }
    double res2 = 4.0 * sum2;

    // Equação 3: 3 + Sum_{i=1 to n} ((-1)^{i+1} * 4 / ((2i)(2i+1)(2i+2)))
    double res3 = 3.0;
    for (int i = 1; i <= n; ++i) {
        double term = 4.0 / ((2.0 * i) * (2.0 * i + 1.0) * (2.0 * i + 2.0));
        if (i % 2 != 0) res3 += term;
        else res3 -= term;
    }

    cout << fixed << setprecision(6);
    cout << res1 << " - " << (res1 / M_PI) << "\n";
    cout << res2 << " - " << (res2 / M_PI) << "\n";
    cout << res3 << " - " << (res3 / M_PI) << "\n";

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    const double pi = M_PI;

    cout.setf(std::ios::fixed);
    cout << setprecision(6);

    double sum1 = 0.0;
    for (int x = 0; x <= n; x++) {
        double term = ((x % 2 == 0) ? 1.0 : -1.0) / (2.0 * x + 1.0);
        sum1 += term;
    }
    double eq1_pi = 4.0 * sum1;
    double perc1 = (eq1_pi / pi) * 100.0;
    cout << eq1_pi << " - " << perc1 / 100.0 * 1.0 << "\n";

    double sum2 = 0.0;
    for (int x = 0; x <= n; x++) {
        double num = 2.0;
        double den = (4.0 * x + 1.0) * (4.0 * x + 3.0);
        sum2 += num / den;
    }
    double eq2_pi = 4.0 * sum2;
    double perc2 = (eq2_pi / pi) * 100.0;
    cout << eq2_pi << " - " << perc2 / 100.0 * 1.0 << "\n";

    double eq3 = 3.0;
    for (int k = 0; k < n; k++) {
        long long a = 2LL * (k + 1);
        long long b = 2LL * (k + 1) + 1;
        long long c = 2LL * (k + 1) + 2;
        double term = 4.0 / (a * b * c);
        if (k % 2 == 0) eq3 += term;
        else eq3 -= term;
    }
    double perc3 = (eq3 / pi) * 100.0;
    cout << eq3 << " - " << perc3 / 100.0 * 1.0 << "\n";

    return 0;
}
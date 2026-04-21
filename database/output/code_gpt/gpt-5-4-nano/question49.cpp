/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    const double EPS = 1e-9;

    auto eq = [&](double x, double y) {
        return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y)));
    };

    if (eq(a, b) && eq(b, c)) {
        cout << "equilatero\n";
    } else if (eq(a, b) || eq(a, c) || eq(b, c)) {
        cout << "isosceles\n";
    } else {
        cout << "escaleno\n";
    }
    return 0;
}
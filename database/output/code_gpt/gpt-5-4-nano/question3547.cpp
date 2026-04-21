/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b;
    long double c, d;
    if (!(cin >> a >> b)) return 0;
    if (!(cin >> c >> d)) return 0;

    long double L = max(c, d);

    long double x = b / a;
    if (fabsl(a) < 1e-30L) {
        cout << "Procura outro lugar, bilu\n";
        return 0;
    }

    const long double EPS = 1e-18L;

    long double maxRadius = 0;

    if (x <= 1.0L + EPS) {
        maxRadius = b;
    } else {
        long double t = sqrtl(x * x - 1.0L);
        long double denom = x + t;
        if (fabsl(denom) < EPS) {
            cout << "Procura outro lugar, bilu\n";
            return 0;
        }
        long double s = (x - t) / denom;
        s = min(max(s, 0.0L), 1.0L);
        long double u = s;
        long double invR2 = (u / (b * b)) + ((1.0L - u) / (a * a));
        if (invR2 <= 0) {
            cout << "Procura outro lugar, bilu\n";
            return 0;
        }
        maxRadius = 1.0L / sqrtl(invR2);
    }

    if (L <= maxRadius + 1e-12L) cout << "Pousa, bilu\n";
    else cout << "Procura outro lugar, bilu\n";

    return 0;
}
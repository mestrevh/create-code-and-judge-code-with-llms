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
    if (!(cin >> b)) return 0;
    if (!(cin >> c)) return 0;

    double x[3] = {a, b, c};
    sort(x, x + 3);
    double p = x[0], q = x[1], r = x[2];

    const double EPS = 1e-9;
    if (p <= 0 || q <= 0 || r <= 0 || p + q <= r + EPS) {
        cout << "-";
        return 0;
    }

    bool ab = fabs(a - b) <= EPS;
    bool ac = fabs(a - c) <= EPS;
    bool bc = fabs(b - c) <= EPS;

    if (ab && ac) cout << "EQUILATERO";
    else if (ab || ac || bc) cout << "ISOSCELES";
    else cout << "ESCALENO";

    return 0;
}
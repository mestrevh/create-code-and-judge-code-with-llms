/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B, C, D;
    if (!(cin >> A >> B)) return 0;
    if (!(cin >> C >> D)) return 0;

    double denom = A - C;
    double x, y;

    if (fabs(denom) < 1e-12) {
        x = 0.0;
        y = A * x + B;
    } else {
        x = (D - B) / denom;
        y = A * x + B;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << x << " " << y;
    return 0;
}
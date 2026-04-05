/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    long double delta = B * B - 4 * A * C;
    long double sqrtDelta = sqrtl(delta);

    long double x1 = (-B - sqrtDelta) / (2 * A);
    long double x2 = (-B + sqrtDelta) / (2 * A);

    cout << fixed << setprecision(2) << (double)x1 << " " << (double)x2;
    return 0;
}
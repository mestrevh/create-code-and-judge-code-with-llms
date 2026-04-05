/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;

    long double a = (long double)(y1 - y2);
    long double b = (long double)(x2 - x1);
    long double c = (long double)(x1 * y2 - x2 * y1);

    cout << fixed << setprecision(2);
    cout << "(" << a << "x) + (" << b << "y) + (" << c << ") = 0";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double h, r;
    if (!(cin >> h)) return 0;
    if (!(cin >> r)) return 0;

    const double pi = 3.14;
    double volume = pi * r * r * h;
    double area = 2.0 * pi * r * (r + h);

    cout.setf(ios::fixed);
    cout << setprecision(2) << volume << "\n" << setprecision(2) << area;
    return 0;
}
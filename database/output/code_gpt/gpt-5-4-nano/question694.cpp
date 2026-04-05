/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double dobroMaior(double a, double b) {
    double m = max(a, b);
    return 2.0 * m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;

    cout << fixed << setprecision(2) << dobroMaior(a, b) << "\n";
    return 0;
}
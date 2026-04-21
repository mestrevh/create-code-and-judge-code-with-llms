/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double h, l, L;
    if (!(cin >> h)) return 0;
    cin >> l >> L;

    double A = L * L;
    double a = l * l;

    double V = (h / 3.0) * (A + a + sqrt(A * a));
    cout << fixed << setprecision(1) << V << "\n";
    return 0;
}
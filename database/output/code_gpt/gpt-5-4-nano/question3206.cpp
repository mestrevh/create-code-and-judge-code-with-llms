/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, d;
    if (!(cin >> a >> d)) return 0;

    double rad = a * M_PI / 180.0;
    double lado = d / cos(rad);

    cout << fixed << setprecision(15) << lado;
    return 0;
}
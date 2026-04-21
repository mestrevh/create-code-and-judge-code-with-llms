/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B, C, D, E, F;
    if (!(cin >> A)) return 0;
    cin >> B >> C;
    cin >> D >> E >> F;

    double det = A * E - B * D;
    double x = (C * E - B * F) / det;
    double y = (A * F - C * D) / det;

    cout << fixed << setprecision(2) << x << "\n" << y << "\n";
    return 0;
}
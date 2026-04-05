/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long h, c, f, r, m;
    if (!(cin >> h)) return 0;
    if (!(cin >> c)) return 0;
    if (!(cin >> f)) return 0;
    if (!(cin >> r)) return 0;
    if (!(cin >> m)) return 0;

    double total = 3.00 * h + 2.50 * c + 2.50 * f + 1.00 * r + 3.00 * m;
    cout << "conta final: " << fixed << setprecision(1) << total << "\n";
    return 0;
}
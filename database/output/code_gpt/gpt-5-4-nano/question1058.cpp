/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double T, M;
    if (!(cin >> T >> M)) return 0;

    const double R = 8.31;
    double v = sqrt(3.0 * R * T / M);

    cout.setf(ios::fixed);
    cout << setprecision(2) << v;
    return 0;
}
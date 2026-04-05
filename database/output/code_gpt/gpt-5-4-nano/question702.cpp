/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;

    long double c = sqrt(a * a + b * b);

    cout << fixed << setprecision(2) << (double)c << "\n";
    return 0;
}
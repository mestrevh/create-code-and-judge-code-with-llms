/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    double media = (2*a + 2*b + 3*c + 3*d) / 10.0;

    cout << fixed << setprecision(2) << "A média ponderada será: " << media;
    return 0;
}
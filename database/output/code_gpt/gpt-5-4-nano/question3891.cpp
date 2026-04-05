/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    double media = (a + b + c) / 3.0;
    double mp1 = (2*a + 2*b + 3*c) / 7.0;
    double mp2 = (1*a + 2*b + 2*c) / 5.0;

    cout << fixed << setprecision(2);
    cout << media << "\n" << mp1 << "\n" << mp2 << "\n";
    return 0;
}
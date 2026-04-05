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
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    double m = min({a, b, c});
    if (m == a) cout << "Primeiro produto";
    else if (m == b) cout << "Segundo produto";
    else cout << "Terceiro produto";

    return 0;
}
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

    double media = (a + b + c + d) / 4.0;

    cout << "A media das alturas eh: " << media;
    return 0;
}
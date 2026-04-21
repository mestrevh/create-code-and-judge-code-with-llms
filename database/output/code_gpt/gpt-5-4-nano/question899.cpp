/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    double mx = -numeric_limits<double>::infinity();

    for (int i = 0; i < 50; i++) {
        cout << "Digite um numero:";
        if (!(cin >> x)) return 0;
        mx = max(mx, x);
    }

    cout << "Maior numero: " << fixed << setprecision(2) << mx;
    return 0;
}
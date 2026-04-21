/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double m;
    cout << "Insira um valor em metros:\n";
    if (!(cin >> m)) return 0;

    double cm = m * 100.0;
    cout << fixed << setprecision(1) << "Resultado: " << cm;
    return 0;
}
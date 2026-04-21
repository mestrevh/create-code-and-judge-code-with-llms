/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double valor;
    long long anos;
    if (!(cin >> valor >> anos)) return 0;

    double taxa = 0.0;
    if (anos == 1) taxa = 0.03;
    else if (anos == 2) taxa = 0.05;

    double total = valor * (1.0 + taxa);

    cout << fixed << setprecision(2) << total;
    return 0;
}
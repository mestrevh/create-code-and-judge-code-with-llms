/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;

    vector<long long> notas = {100, 50, 20, 10, 5, 2, 1};
    for (long long v : notas) {
        long long qtd = X / v;
        X %= v;
        cout << qtd << " nota(s) de R$ " << fixed << setprecision(2) << (double)v << "\n";
    }
    return 0;
}
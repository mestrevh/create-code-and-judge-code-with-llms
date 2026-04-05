/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long paes, broas;
    if (!(cin >> paes >> broas)) return 0;

    double arrecadacao = paes * 0.45 + broas * 2.25;
    double poupanca = arrecadacao * 0.15;

    cout << fixed << setprecision(2) << arrecadacao << "\n" << poupanca << "\n";
    return 0;
}
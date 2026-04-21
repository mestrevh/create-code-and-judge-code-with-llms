/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dias;
    if (!(cin >> dias)) return 0;

    long long anos = dias / 365;
    dias %= 365;
    long long meses = dias / 30;
    long long diasRestantes = dias % 30;

    cout << anos << " ano(s)\n";
    cout << meses << " mes(es)\n";
    cout << diasRestantes << " dia(s)\n";
    return 0;
}
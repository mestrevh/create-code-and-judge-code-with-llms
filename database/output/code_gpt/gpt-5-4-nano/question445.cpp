/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long dias, kmTotal;
    if (!(cin >> dias)) return 0;
    cin >> kmTotal;

    long long cota = dias * 100;
    long long excedente = max(0LL, kmTotal - cota);

    double total = dias * 90.0 + excedente * 12.0;

    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}
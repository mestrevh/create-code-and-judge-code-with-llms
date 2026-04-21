/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double p[3];
    long long q[3];
    if (!(cin >> p[0])) return 0;
    cin >> p[1] >> p[2];
    cin >> q[0] >> q[1] >> q[2];

    long double total = (long double)p[0] * q[0] + (long double)p[1] * q[1] + (long double)p[2] * q[2];

    cout << fixed << setprecision(2) << "Valor: R$" << (double)total << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double mlRato;
    long double gRato;
    long double kgPessoa;
    if (!(cin >> mlRato)) return 0;
    cin >> gRato >> kgPessoa;

    long double totalMlPessoa = mlRato * (kgPessoa * 1000.0L) / gRato;

    long double liters = totalMlPessoa / 10.0L;
    cout << fixed << setprecision(1)
         << liters << "L de refrigerante poderiam levar uma pessoa de "
         << fixed << setprecision(1) << (double)kgPessoa
         << "kg a morte.";
    return 0;
}
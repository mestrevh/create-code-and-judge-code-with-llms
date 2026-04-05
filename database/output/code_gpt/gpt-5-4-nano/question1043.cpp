/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double dollars;
    if (!(cin >> dollars)) return 0;
    double reais = dollars * 3.55;
    cout << fixed << setprecision(2) << reais;
    return 0;
}
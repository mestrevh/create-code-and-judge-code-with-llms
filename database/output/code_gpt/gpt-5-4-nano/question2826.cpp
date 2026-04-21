/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double g;
    if (!(cin >> g)) return 0;
    
    long double liters = g * 3.7854L;
    cout << fixed << setprecision(2);
    cout << g << " GALÕES -> " << liters << " LITROS";
    return 0;
}
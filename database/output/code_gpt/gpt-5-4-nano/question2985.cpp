/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double distancia, litros;
    if (!(cin >> distancia >> litros)) return 0;
    
    double km_por_litro = distancia / litros;
    cout << fixed << setprecision(1) << km_por_litro;
    return 0;
}
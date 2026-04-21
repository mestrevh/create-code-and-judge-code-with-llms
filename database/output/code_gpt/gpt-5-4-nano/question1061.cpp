/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double r1, r2;
    if (!(cin >> r1 >> r2)) return 0;
    
    const long double pi = 3.14L;
    long double a1 = pi * r1 * r1;
    long double a2 = pi * r2 * r2;
    
    const long double eps = 1e-12L;
    if (fabsl(a1 - a2) <= eps) {
        cout << "Iguais";
    } else if (a1 > a2) {
        cout << "Primeiro circulo";
    } else {
        cout << "Segundo circulo";
    }
    return 0;
}
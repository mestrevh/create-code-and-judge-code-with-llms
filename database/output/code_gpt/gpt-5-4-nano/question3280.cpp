/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double salario;
    if (!(cin >> salario)) return 0;
    
    double novo = salario * 1.075;
    cout << fixed << setprecision(2) << novo;
    return 0;
}
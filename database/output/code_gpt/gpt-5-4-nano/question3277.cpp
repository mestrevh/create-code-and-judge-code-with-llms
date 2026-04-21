/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double nota;
    if (!(cin >> nota)) return 0;
    
    if (nota >= 0 && nota <= 10) cout << "valida";
    else cout << "invalida";
    return 0;
}
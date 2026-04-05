/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double a, b;
    if (!(cin >> a >> b)) return 0;
    
    if (a < 0 && b < 0) cout << "NEGATIVOS";
    else cout << "NAO SAO AMBOS NEGATIVOS";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double largura, comprimento, altura;
    if (!(cin >> largura >> comprimento >> altura)) return 0;
    
    if (largura <= 45.0 && comprimento <= 56.0 && altura <= 25.0) {
        cout << "PERMITIDA";
    } else {
        cout << "PROIBIDA";
    }
    return 0;
}
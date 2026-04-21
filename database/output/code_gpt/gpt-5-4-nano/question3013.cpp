/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double largura, comprimento;
    if (!(cin >> largura >> comprimento)) return 0;
    
    double area = largura * comprimento;
    cout << fixed << setprecision(2) << area;
    return 0;
}
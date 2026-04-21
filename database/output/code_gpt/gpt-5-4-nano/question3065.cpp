/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double largura, altura;
    if (!(cin >> largura >> altura)) return 0;
    double diagonal = sqrt(largura * largura + altura * altura);
    
    cout << fixed << setprecision(10) << diagonal;
    return 0;
}
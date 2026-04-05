/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double nota1, nota2;
    if (!(cin >> nota1 >> nota2)) return 0;
    
    const double peso1 = 6.0;
    const double peso2 = 4.0;
    double media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
    
    cout << fixed << setprecision(1) << "Média= " << media;
    return 0;
}
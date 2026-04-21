/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    
    double media = (a + b + c) / 3.0;
    
    if (media >= 7.0) cout << "aprovado";
    else if (media < 3.0) cout << "reprovado";
    else cout << "prova final";
    
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double broas, paes;
    if (!(cin >> broas >> paes)) return 0;
    
    long double total = broas * 1.50L + paes * 0.20L;
    long double poupanca = total * 0.10L;
    
    cout << "O valor a ser guardado na poupança será R$ " << fixed << setprecision(2) << poupanca;
    return 0;
}
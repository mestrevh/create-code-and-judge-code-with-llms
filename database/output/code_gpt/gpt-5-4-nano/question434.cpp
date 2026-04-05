/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long pagos;
    if (!(cin >> pagos)) return 0;
    
    const long long total = 260;
    const long long maxSem = 24;
    
    long long restantes = total - pagos;
    if (restantes <= 0) {
        cout << 0;
        return 0;
    }
    
    long long semestres = (restantes + maxSem - 1) / maxSem;
    cout << semestres;
    return 0;
}
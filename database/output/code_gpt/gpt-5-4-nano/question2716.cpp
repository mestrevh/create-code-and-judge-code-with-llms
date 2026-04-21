/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(1);
    for (double p = 5.0; p >= 1.0 - 1e-9; p -= 0.5) {
        int steps = (int)llround((5.0 - p) / 0.5);
        long long publicos = 120 + 26LL * steps;
        long long lucro = llround(p * publicos) - 200;
        cout << "preco do ingresso: R$ " << p
             << " / publico esperado: " << publicos
             << " / lucro esperado: R$ " << lucro;
        if (p > 1.0 + 1e-9) cout << "\n";
    }
    return 0;
}
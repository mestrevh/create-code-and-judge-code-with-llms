/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double preco, pagamento;
    if (!(cin >> preco)) return 0;
    if (!(cin >> pagamento)) return 0;

    double litros = pagamento / preco;

    cout << fixed << setprecision(2)
         << "Você conseguiu colocar " << litros << " litros!";
    return 0;
}
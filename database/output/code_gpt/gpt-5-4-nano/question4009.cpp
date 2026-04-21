/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double compra;
    cout << "Digite o valor de compra do produto: ";
    if (!(cin >> compra)) return 0;

    double lucro = (compra < 20.0) ? 0.45 : 0.30;
    double venda = compra * (1.0 + lucro);

    cout << "O produto deve ser vendido a R$ " << fixed << setprecision(2) << venda;
    return 0;
}
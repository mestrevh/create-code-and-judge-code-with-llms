/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario;
    if (!(cin >> salario)) return 0;

    const double teto = 2594.58;
    double desconto;
    if (salario <= teto) desconto = salario * 0.11;
    else desconto = teto * 0.11;

    cout << fixed << setprecision(2);
    cout << "Desconto do INSS: R$ " << desconto << "\n";
    return 0;
}
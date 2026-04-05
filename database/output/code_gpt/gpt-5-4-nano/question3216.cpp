/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double salario;
    if (!(cin >> salario)) return 0;

    long double teto = 1050.0L;
    long double desconto;

    if (salario <= teto) desconto = 0.11L * salario;
    else desconto = 0.11L * teto;

    cout.setf(ios::fixed);
    cout << setprecision(6) << "Desconto do INSS: R$ " << (double)desconto << "\n";
    return 0;
}
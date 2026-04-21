/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double dias, km;
    cout << "Digite a quantidade de dias de locacao: ";
    if (!(cin >> dias)) return 0;
    cout << "Digite a quantidade de km rodados: ";
    if (!(cin >> km)) return 0;

    double custo = dias * 30.0 + km * 0.01;
    custo *= 0.90;

    cout << fixed << setprecision(6) << "Valor a pagar pelo aluguel: R$ " << custo;
    return 0;
}
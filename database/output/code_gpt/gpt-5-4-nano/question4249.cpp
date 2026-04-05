/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double kwh;
    cout << "Digite o valor real em KWh consumido:\n";
    if (!(cin >> kwh)) return 0;

    double price = kwh * 1.50;
    double discount = price * 0.85;

    cout << fixed << setprecision(2);
    cout << "Valor a ser pago: R$ " << price << " reais\n";
    cout << "Valor a ser pago com desconto: R$ " << discount << " reais\n";
    return 0;
}
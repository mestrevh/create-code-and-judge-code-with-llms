/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double total;
    cout << "Digite o valor total do premio em dinheiro: ";
    if (!(cin >> total)) return 0;

    double p1 = total * 0.60;
    double p2 = total * 0.30;
    double p3 = total * 0.10;

    cout << "Premio para o 1 lugar: R$ " << p1 << "\n";
    cout << "Premio para o 2 lugar: R$ " << p2 << "\n";
    cout << "Premio para o 3 lugar: R$ " << p3 << "\n";
    return 0;
}
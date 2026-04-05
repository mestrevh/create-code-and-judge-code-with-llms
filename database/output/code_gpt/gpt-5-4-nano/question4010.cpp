/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Digite a quantidade de macas: ";
    if (!(cin >> n)) return 0;

    double price = (n < 12) ? 0.30 : 0.25;
    double total = n * price;

    cout << fixed << setprecision(2);
    cout << "Valor total: R$ " << total << "\n";
    return 0;
}
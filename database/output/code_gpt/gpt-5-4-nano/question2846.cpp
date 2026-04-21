/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double COST = 800.0;

    double value;
    int qty;
    double totalToTrade = 0.0;
    int itemsToTrade = 0;

    for (int i = 0; i < 6; i++) {
        if (!(cin >> value >> qty)) return 0;
        if (qty > 1) {
            itemsToTrade += (qty - 1);
            totalToTrade += (qty - 1) * value;
        }
    }

    cout << "Insira a quantidade e valor de cada presente:\n";
    cout << "Numero de presentes a serem trocados: " << itemsToTrade << "\n";
    if (totalToTrade + 1e-9 >= COST) {
        cout << "Voce PODERA adquirir o ar condicionado com as trocas";
    } else {
        cout << "Voce NAO PODERA adquirir o ar condicionado com as trocas";
    }
    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total_money = 0.0;
    int total_items_exchanged = 0;

    for (int i = 0; i < 6; ++i) {
        double value;
        int qty;
        if (!(cin >> value >> qty)) break;
        if (qty > 1) {
            int extra = qty - 1;
            total_items_exchanged += extra;
            total_money += (value * extra);
        }
    }

    cout << total_items_exchanged << "\n";
    if (total_money >= 800.0) {
        cout << "SIM" << "\n";
    } else {
        cout << "NAO" << "\n";
    }

    return 0;
}
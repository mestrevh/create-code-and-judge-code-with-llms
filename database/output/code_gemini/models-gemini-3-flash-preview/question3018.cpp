/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double price_per_liter, total_payment;
    while (cin >> price_per_liter >> total_payment) {
        if (price_per_liter == 0) continue;
        double liters = total_payment / price_per_liter;
        cout << "Você conseguiu colocar " << fixed << setprecision(2) << liters << " litros!" << "\n";
    }

    return 0;
}
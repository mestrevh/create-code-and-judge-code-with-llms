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

    double capital, rate;
    int years;

    if (!(cin >> capital >> rate >> years)) {
        return 0;
    }

    int total_quarters = years * 4;
    double current_balance = capital;

    cout << fixed << setprecision(2);

    for (int i = 0; i < total_quarters; ++i) {
        double yield = current_balance * rate;
        current_balance += yield;
        cout << "Rendimento: " << yield << " Montante: " << current_balance << "\n";
    }

    return 0;
}
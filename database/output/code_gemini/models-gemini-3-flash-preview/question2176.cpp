/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double us_gallon_usd, br_liter_brl, dollar_rate;

    while (cin >> us_gallon_usd >> br_liter_brl >> dollar_rate) {
        // Calculation based on the fixed factor of 3.8 liters per gallon
        double us_liter_brl = (us_gallon_usd * dollar_rate) / 3.8;

        // Output formatting: 2 decimal places
        cout << "Gasolina EUA: R$ " << fixed << setprecision(2) << us_liter_brl << "\n";
        cout << "Gasolina Brasil: R$ " << fixed << setprecision(2) << br_liter_brl << "\n";

        // Comparison using a small epsilon to account for floating point precision
        if (abs(us_liter_brl - br_liter_brl) < 1e-9) {
            cout << "Igual\n";
        } else if (us_liter_brl < br_liter_brl) {
            cout << "Mais barata nos EUA\n";
        } else {
            cout << "Mais barata no Brasil\n";
        }
    }

    return 0;
}
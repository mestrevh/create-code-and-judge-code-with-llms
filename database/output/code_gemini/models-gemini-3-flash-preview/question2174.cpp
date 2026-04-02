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

    double m3, cost_per_liter;
    while (cin >> m3 >> cost_per_liter) {
        double liters = m3 * 1000.0;
        double water_value = liters * cost_per_liter;
        double sewer_value = water_value * 0.8;
        double total_value = water_value + sewer_value;

        cout << fixed << setprecision(2) << water_value << "\n";
        cout << fixed << setprecision(2) << sewer_value << "\n";
        cout << fixed << setprecision(2) << total_value << "\n";
    }

    return 0;
}
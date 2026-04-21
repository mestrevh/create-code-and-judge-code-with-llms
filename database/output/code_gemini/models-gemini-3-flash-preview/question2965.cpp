/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double area;
    if (!(cin >> area)) return 0;

    double liters_needed = area / 7.0;

    // Case a: Only 24 liter cans
    long long cans_a = (long long)ceil(liters_needed / 24.0);
    double price_a = cans_a * 91.00;

    // Case b: Only 5.4 liter cans
    long long cans_b = (long long)ceil(liters_needed / 5.4);
    double price_b = cans_b * 23.00;

    // Case c: Combination (Maximize 24L cans as integers, then rest in 5.4L)
    long long cans24_c = (long long)floor(liters_needed / 24.0);
    double remaining_liters = liters_needed - (cans24_c * 24.0);
    long long cans54_c = 0;
    
    // Use epsilon to handle floating point precision issues
    if (remaining_liters > 1e-9) {
        cans54_c = (long long)ceil(remaining_liters / 5.4);
    }
    double price_c = (cans24_c * 91.00) + (cans54_c * 23.00);

    cout << fixed << setprecision(2);
    cout << "a) " << cans_a << " lata(s) de 24 litros: R$ " << price_a << "\n";
    cout << "b) " << cans_b << " lata(s) de 5.4 litros: R$ " << price_b << "\n";
    cout << "c) " << cans24_c << " lata(s) de 24 litros e " << cans54_c << " lata(s) de 5.4 litros: R$ " << price_c << endl;

    return 0;
}
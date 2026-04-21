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

    double n, p;
    while (cin >> n >> p) {
        // a) Valor promocional da diária (75% of normal rate, rounded to 2 decimal places)
        double p_promo = round(p * 0.75 * 100.0) / 100.0;

        // b) Valor total a ser arrecadado caso a ocupação atinja 100% (2 days of weekend)
        double v_100 = p_promo * n * 2.0;

        // c) Valor total a ser arrecadado caso a ocupação atinja 70% (2 days of weekend)
        // 70% of apartments * promotional rate * 2 days
        double v_70 = p_promo * (n * 0.7) * 2.0;

        // d) Valor que o hotel deixará de arrecadar em virtude da promoção, caso a ocupação atinja 100%
        // Difference between normal total (100% occupancy) and promotional total (100% occupancy)
        double v_normal_total_100 = p * n * 2.0;
        double v_loss = v_normal_total_100 - v_100;

        // The example outputs show 1 decimal place even for integers (e.g., 60.0, 6000.0)
        // but also show 2 decimal places when necessary (e.g., 112.49).
        // Standard competitive programming practice is numerical comparison.
        // However, to mimic the provided format, we use default formatting.
        cout << p_promo << "\n";
        cout << v_100 << "\n";
        cout << v_70 << "\n";
        cout << v_loss << "\n";
    }

    return 0;
}
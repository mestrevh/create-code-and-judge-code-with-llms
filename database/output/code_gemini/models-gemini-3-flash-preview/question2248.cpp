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

    long double x;
    int t;
    
    if (!(cin >> x >> t)) return 0;

    if (t <= 0) {
        cout << fixed << setprecision(3) << 0.000 << endl;
        return 0;
    }

    long double total = x;
    long double current_term = x;

    if (t >= 2) {
        current_term = -(x * x) / 6.0; // -X^2 / 3!
        total += current_term;
        
        for (int i = 3; i <= t; ++i) {
            // Each term n relates to n-1 by: -X^2 / ((2n-2)*(2n-1))
            // Term 3 (i=3): Term 2 * -X^2 / (4 * 5) = X^4 / 5!
            // Term 4 (i=4): Term 3 * -X^2 / (6 * 7) = -X^6 / 7!
            current_term *= -(x * x) / (long double)((2 * i - 2) * (2 * i - 1));
            total += current_term;
        }
    }

    cout << fixed << setprecision(3) << fabsl(total) << endl;

    return 0;
}
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

    double total;
    if (cin >> total) {
        // Carlos and André pay the floor of (total / 3)
        // We use a small epsilon (1e-9) to handle potential double precision errors
        double share = floor(total / 3.0 + 1e-9);
        
        // Felipe pays the remainder
        double felipe = total - (2.0 * share);

        // Printing results with the precision format shown in test cases
        // Carlos and André: 1 decimal place
        cout << fixed << setprecision(1) << share << "\n";
        cout << fixed << setprecision(1) << share << "\n";
        // Felipe: 2 decimal places
        cout << fixed << setprecision(2) << felipe << "\n";
    }

    return 0;
}
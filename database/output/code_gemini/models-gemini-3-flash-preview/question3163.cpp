/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: Calculate the b-th root of a.
 * The examples (8 3 -> 2, 16 4 -> 2, 512 3 -> 8) indicate that the 
 * problem expects the result of the b-th root of a, likely as an integer
 * based on the provided output formats.
 */

int main() {
    // Optimization for competitive programming I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double a, b;
    // Read input until EOF
    while (cin >> a >> b) {
        if (a == 0) {
            cout << 0 << "\n";
            continue;
        }

        long double result;
        if (a > 0) {
            // Standard root for positive base
            result = pow(a, 1.0L / b);
        } else {
            // For negative a, the root only exists in real numbers if b is odd
            // pow(negative, fractional) in C++ returns NaN, so we handle it manually
            result = -pow(-a, 1.0L / b);
        }

        // Output rounded to nearest integer as per example formats
        cout << (long long)round(result) << "\n";
    }

    return 0;
}
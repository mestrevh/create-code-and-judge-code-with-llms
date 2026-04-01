/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problem: Histograma 02
 * Description: Generates a histogram from N values in 10 regular intervals.
 * Intervals: [0.0, 1.0], (1.0, 2.0], ..., (9.0, 10.0]
 * Output: Histogram bars from highest interval down to lowest.
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Process input until EOF (handling "multiplas entradas" topic)
    while (cin >> n) {
        // Frequency buckets for 10 intervals
        // counts[0]: [0.0, 1.0]
        // counts[1]: (1.0, 2.0]
        // ...
        // counts[9]: (9.0, 10.0]
        vector<int> counts(10, 0);
        int max_f = 0;

        for (int i = 0; i < n; ++i) {
            double val;
            if (!(cin >> val)) break;

            // Convert double to integer representation (e.g., 9.7 -> 97)
            // Adding 0.5 before casting to int ensures proper rounding for 1 decimal place
            int v = (int)(val * 10.0 + 0.5);

            int b;
            if (v <= 10) {
                // First interval [0.0, 1.0] is closed on both sides
                b = 0;
            } else {
                // Intervals (1.0, 2.0] through (9.0, 10.0] are open-closed
                // Formula: (integer_val - 1) / 10
                // Example: 1.1 -> 11. (11-1)/10 = 1.
                // Example: 2.0 -> 20. (20-1)/10 = 1.
                // Example: 10.0 -> 100. (100-1)/10 = 9.
                b = (v - 1) / 10;
            }

            // Boundary check and increment count
            if (b >= 0 && b < 10) {
                counts[b]++;
            }
        }

        // Determine the maximum frequency across all buckets for the horizontal axis
        for (int i = 0; i < 10; ++i) {
            if (counts[i] > max_f) {
                max_f = counts[i];
            }
        }

        // Print histogram top axis
        cout << "^\n";

        // Print bars from interval 10 down to interval 1
        // Interval 10 is index 9, Interval 1 is index 0
        for (int i = 9; i >= 0; --i) {
            cout << "|";
            for (int j = 0; j < counts[i]; ++j) {
                cout << "*";
            }
            cout << "\n";
        }

        // Print bottom horizontal axis
        // Format: '+' followed by max_f dashes and then '>'
        cout << "+";
        for (int i = 0; i < max_f; ++i) {
            cout << "-";
        }
        cout << ">\n";
    }

    return 0;
}
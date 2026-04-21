/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: A Viagem Dos Gêmeos
 * Goal: Print a pyramid structure based on N floors and calculate total cost.
 * Symbols: '.' (empty), '&' (window), '-' (support), '#' (base).
 * Costs: & = 200, - = 50, # = 100.
 */

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Input constraints: 1 <= n <= 99
    if (!(cin >> n)) return 0;

    long long windows = 0;
    long long supports = 0;

    // Build floors 1 to n
    for (int i = 1; i <= n; ++i) {
        // Leading dots: n - i
        for (int j = 0; j < n - i; ++j) {
            cout << ".";
        }

        // Center structure: width is 2*i - 1
        // Alternates between '&' and '-'
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (j % 2 != 0) {
                cout << "&";
                windows++;
            } else {
                cout << "-";
                supports++;
            }
        }

        // Trailing dots: n - i
        for (int j = 0; j < n - i; ++j) {
            cout << ".";
        }
        cout << "\n";
    }

    // Build the base row
    // Base width is always 2*n - 1
    long long base_count = 2 * n - 1;
    for (int i = 0; i < base_count; ++i) {
        cout << "#";
    }
    cout << "\n";

    // Calculate total cost
    // Cost formula: Windows * 200 + Supports * 50 + Base * 100
    long long total_cost = (windows * 200) + (supports * 50) + (base_count * 100);

    // Final Output
    cout << "O valor total foi: " << total_cost << endl;

    return 0;
}
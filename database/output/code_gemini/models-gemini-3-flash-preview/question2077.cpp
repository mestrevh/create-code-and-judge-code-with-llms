/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Determine if a natural number n is "triangular".
 * Definition: A number is triangular if it's the product of three consecutive natural numbers.
 * Complexity: O(n^(1/3)), which is approximately 2*10^6 iterations for n = 2^63 - 1.
 */

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // Reading n. Natural numbers are typically 64-bit integers in CP unless specified otherwise.
    if (!(cin >> n)) return 0;

    // A triangular number as defined must be non-negative.
    if (n < 0) {
        cout << "Falso" << endl;
        return 0;
    }

    bool found = false;
    // Iterate through potential starting numbers i for the product i * (i+1) * (i+2)
    // We start from i = 1 as most definitions of this problem exclude 0, 
    // but the logic remains efficient for any starting point.
    for (long long i = 1; ; ++i) {
        // Use __int128 for the product calculation to safely handle values near LLONG_MAX
        unsigned __int128 p1 = i;
        unsigned __int128 p2 = i + 1;
        unsigned __int128 p3 = i + 2;
        unsigned __int128 prod = p1 * p2 * p3;

        if (prod == (unsigned __int128)n) {
            // Found the consecutive numbers. Format the output according to test cases.
            cout << i << " * " << i + 1 << " * " << i + 2 << " = " << n << "\n";
            cout << "Verdadeiro" << endl;
            found = true;
            break;
        } else if (prod > (unsigned __int128)n) {
            // Product exceeded n, no need to check further.
            break;
        }

        // Safety break for extremely large i values beyond 64-bit limits
        if (i > 2097151) break;
    }

    if (!found) {
        cout << "Falso" << endl;
    }

    return 0;
}
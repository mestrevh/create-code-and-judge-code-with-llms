/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b;
    // Reading input values N, A, and B
    if (!(cin >> n >> a >> b)) return 0;

    // Define the range [low, high] regardless of the order of A and B
    long long low = min(a, b);
    long long high = max(a, b);

    // Case where N is 0: the only multiple is 0 itself
    if (n == 0) {
        if (low <= 0 && high >= 0) {
            cout << 0 << "\n";
        } else {
            cout << "INEXISTENTE" << "\n";
        }
        return 0;
    }

    // A multiple of N is also a multiple of -N, so we work with its absolute value
    if (n < 0) n = -n;

    // Finding the first multiple of N that is >= low
    long long start;
    if (low >= 0) {
        start = ((low + n - 1) / n) * n;
    } else {
        // In C++, integer division of negatives truncates toward zero
        // e.g., -10 / 3 = -3. -3 * 3 = -9. -9 is the first multiple >= -10.
        start = (low / n) * n;
    }

    // Safety adjustments to ensure start is the smallest multiple >= low
    while (start < low) start += n;
    while (start - n >= low) start -= n;

    bool found = false;
    // Iterate and print all multiples of N within the range [low, high]
    for (long long i = start; i <= high; ) {
        cout << i << "\n";
        found = true;
        // Check for overflow before incrementing
        if (high - i < n) break;
        i += n;
    }

    // If no multiple was found, print the required message
    if (!found) {
        cout << "INEXISTENTE" << "\n";
    }

    return 0;
}
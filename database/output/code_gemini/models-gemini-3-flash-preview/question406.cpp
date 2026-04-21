/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Sum of positive integers in a given interval [A, B].
 * Complexity: O(1) time, O(1) space.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    // Normalize interval to [low, high]
    long long low = min(a, b);
    long long high = max(a, b);

    // We only care about integers x such that x >= 1 and low <= x <= high
    long long start = max(1LL, low);
    long long end = high;

    if (start > end) {
        // No positive integers in the interval
        cout << 0 << "\n";
    } else {
        // Sum of integers from start to end using the arithmetic progression formula:
        // Sum(1..n) = n * (n + 1) / 2
        // Sum(start..end) = Sum(1..end) - Sum(1..start-1)
        unsigned __int128 s_end = (unsigned __int128)end * (end + 1) / 2;
        unsigned __int128 s_start_minus_1 = (unsigned __int128)(start - 1) * start / 2;
        
        long long result = (long long)(s_end - s_start_minus_1);
        cout << result << "\n";
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <bitset>

using namespace std;

/**
 * Problem: Comida de Graça é Bom ou Ruim?
 * Approach: This is a 0/1 Knapsack variation (Subset Sum Problem).
 * João wants to maximize the energy sum S such that S <= 480 minutes.
 * Since N <= 1000 and the capacity W = 480 is small, we can use 
 * Dynamic Programming with Bitset optimization to solve this efficiently.
 * Complexity: O(T * N * W / 64) which easily fits within the 3s time limit.
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        // Read the number of available foods
        if (!(cin >> N)) break;

        // dp[i] will be true if energy sum 'i' is reachable
        // Capacity is 480 minutes
        bitset<481> dp;
        dp.set(0); // Sum of 0 is always possible

        for (int i = 0; i < N; ++i) {
            int f;
            cin >> f;
            // Only process energy values that could contribute to a sum <= 480
            if (f >= 1 && f <= 480) {
                // For each food, João can either take it or not.
                // Using bitset shift and OR operation to update reachable sums.
                dp |= (dp << f);
            }
        }

        // Find the largest reachable sum index <= 480
        for (int i = 480; i >= 0; --i) {
            if (dp.test(i)) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}
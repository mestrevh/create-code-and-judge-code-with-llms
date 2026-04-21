/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Amusement Park (Knapsack Variation)
 * 
 * Analysis:
 * - N toys, each with cost C[i].
 * - Fun for toy i on k-th ride: F(i, k) = S[i] - (k-1)^2 * B[i].
 * - Fun becomes zero when F(i, k) <= 0.
 * - Total credits K per visit. Multiple visits (V).
 * - Maximize total fun per visit.
 * 
 * Constraints:
 * - N <= 100
 * - S[i], B[i] <= 1000
 * - C[i] <= 25000
 * - K <= 25000
 * - V <= 1000
 * 
 * Solution:
 * Since fun F(i, k) decreases as k increases, the problem can be modeled as a 0/1 Knapsack
 * where each possible ride (with F(i, k) > 0) is a separate item. Because a later ride 
 * provides less fun than an earlier ride for the same cost, the knapsack algorithm 
 * will always prioritize the earlier rides on the same toy.
 * 
 * Total items: N * ~32 (max rides per toy) ≈ 3200.
 * Capacity: 25000.
 * Complexity: O(TotalItems * MaxK) = 3200 * 25000 = 80,000,000 operations, which fits in 1s.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // dp[c] stores the maximum fun obtainable with at most 'c' credits.
    // Using long long to prevent potential overflow, although int should suffice (3.2e6 max fun).
    vector<long long> dp(25001, 0);

    for (int i = 0; i < n; ++i) {
        long long s, b, c;
        cin >> s >> b >> c;
        
        // Generate all beneficial rides for this toy
        for (int k = 1; ; ++k) {
            long long ride_fun = s - (long long)(k - 1) * (k - 1) * b;
            if (ride_fun <= 0) break;
            
            // Standard 0/1 knapsack transition
            // Iterate backwards to ensure each item (ride) is used at most once
            for (int j = 25000; j >= c; --j) {
                if (dp[j - c] + ride_fun > dp[j]) {
                    dp[j] = dp[j - c] + ride_fun;
                }
            }
        }
    }

    int v;
    if (!(cin >> v)) return 0;
    for (int j = 0; j < v; ++j) {
        int k_val;
        cin >> k_val;
        // The constraints state K <= 25000, but we safety-check the index.
        if (k_val > 25000) k_val = 25000;
        if (k_val < 0) k_val = 0;
        
        // Print result for each visit in the format "index: max_fun"
        cout << j << ": " << dp[k_val] << "\n";
    }

    return 0;
}
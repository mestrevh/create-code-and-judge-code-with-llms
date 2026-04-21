/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: The Garden of Combinations
 * Approach: Backtracking to generate all k-sized subsets from n elements.
 * Complexity: O(k * C(n, k)), where C(n, k) is the binomial coefficient.
 */

void solve(int n, int k, int start, int depth, vector<int>& current) {
    // Base case: if the current combination has k elements, print it
    if (depth == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i] << (i == k - 1 ? "" : " ");
        }
        cout << '\n';
        return;
    }

    // Iterate through possible next elements
    // Optimization: only loop while there are enough elements left to complete the combination
    for (int i = start; i <= n; ++i) {
        if (n - i + 1 < k - depth) break; // Pruning
        
        current[depth] = i;
        solve(n, k, i + 1, depth + 1, current);
    }
}

int main() {
    // Standard CP I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Basic validation based on combination rules
    if (k > 0 && k <= n) {
        vector<int> current(k);
        solve(n, k, 1, 0, current);
    } else if (k == 0) {
        // Technically, 1 way to choose 0 items is an empty set, 
        // but in CP competitive problems, usually no output is expected.
        return 0;
    }

    return 0;
}
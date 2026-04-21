/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Edit Distance (Levenshtein Distance)
 * Complexity: O(N * M) time and O(min(N, M)) space
 * Approach: Dynamic Programming with space optimization (two-row technique)
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string A, B;
        if (!(cin >> A >> B)) break;

        int n = A.length();
        int m = B.length();

        // Space optimization: Ensure B is the shorter string
        if (m > n) {
            swap(A, B);
            swap(n, m);
        }

        // We only need two rows of the DP table
        // dp[0] represents the previous row, dp[1] represents the current row
        vector<int> dp[2];
        dp[0].resize(m + 1);
        dp[1].resize(m + 1);

        // Base case: transforming empty string A to string B of length j
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }

        // DP state transitions
        for (int i = 1; i <= n; ++i) {
            int cur = i % 2;
            int pre = (i - 1) % 2;

            // Base case: transforming string A of length i to empty string B
            dp[cur][0] = i;

            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    // Characters match, no new operation needed
                    dp[cur][j] = dp[pre][j - 1];
                } else {
                    // 1 + min(Delete from A, Insert into A, Substitute)
                    int del = dp[pre][j];
                    int ins = dp[cur][j - 1];
                    int sub = dp[pre][j - 1];
                    
                    int min_val = del;
                    if (ins < min_val) min_val = ins;
                    if (sub < min_val) min_val = sub;
                    
                    dp[cur][j] = 1 + min_val;
                }
            }
        }

        // The answer is the final cell of the virtual DP table
        cout << dp[n % 2][m] << "\n";
    }

    return 0;
}
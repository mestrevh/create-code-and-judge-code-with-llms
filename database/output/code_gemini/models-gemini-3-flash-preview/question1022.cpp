/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Static DP table to handle strings up to 1000 characters.
// Using a static global array ensures the memory is allocated once and stays in the data segment.
static int dp[1001][1001];

/**
 * The problem asks for the length of the Longest Palindromic Subsequence (LPS).
 * The standard O(N^2) Dynamic Programming approach:
 * dp[i][j] = length of the longest palindromic subsequence in substring line[i...j].
 * 
 * Recurrence:
 * If line[i] == line[j]:
 *    dp[i][j] = dp[i+1][j-1] + 2
 * Else:
 *    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
 */

int main() {
    // Standard competitive programming I/O optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string line;

    // Read number of test cases.
    if (!(cin >> t)) return 0;

    // Consume the remaining part of the first line (after T).
    getline(cin, line);

    while (t--) {
        // Read the word for the current test case.
        if (!getline(cin, line)) break;

        // Basic sanitization for potential carriage return characters (\r).
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        int n = (int)line.length();
        if (n == 0) {
            cout << "0\n";
            continue;
        }

        // Iterative DP implementation.
        // Outer loop goes backwards to respect the dependency dp[i+1][j-1].
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1; // Base case: a single character is always a palindrome of length 1.
            for (int j = i + 1; j < n; j++) {
                if (line[i] == line[j]) {
                    // If characters at boundaries match.
                    if (i + 1 == j) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    // If characters don't match, take the max length by excluding one of the boundaries.
                    int opt1 = dp[i + 1][j];
                    int opt2 = dp[i][j - 1];
                    dp[i][j] = (opt1 > opt2) ? opt1 : opt2;
                }
            }
        }

        // The result for the whole string is stored in dp[0][n-1].
        cout << dp[0][n - 1] << "\n";
    }

    return 0;
}
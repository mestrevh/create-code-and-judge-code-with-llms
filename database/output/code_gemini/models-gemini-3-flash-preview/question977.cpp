/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The DP table is declared globally to handle large constraints and avoid stack overflow.
// N and K are both up to 2000, so a 2001x2001 table is required (~16MB).
int dp[2001][2001];

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> t(n), m(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> t[i] >> m[i])) break;
    }

    /*
     * This problem is equivalent to the 0/1 Knapsack problem.
     * We want to minimize the total sadness S of participated events, 
     * given that the total fear F (sum of fears of events not attended) <= K.
     * 
     * Let y[i] = 1 if Ryan does NOT attend event i, and 0 otherwise.
     * Fear F = sum(y[i] * m[i]) <= K.
     * Sadness S = sum((1 - y[i]) * t[i]) = total_t - sum(y[i] * t[i]).
     * Minimizing S is equivalent to maximizing the "avoided sadness" sum(y[i] * t[i]).
     */

    // DP to find the maximum avoided sadness for every possible fear level up to K
    for (int i = 1; i <= n; ++i) {
        int current_t = t[i - 1];
        int current_m = m[i - 1];
        for (int w = 0; w <= k; ++w) {
            dp[i][w] = dp[i - 1][w]; // Case: Event i-1 is attended (y[i-1] = 0)
            if (w >= current_m) {
                // Case: Event i-1 is NOT attended (y[i-1] = 1)
                int val = dp[i - 1][w - current_m] + current_t;
                if (val > dp[i][w]) {
                    dp[i][w] = val;
                }
            }
        }
    }

    /*
     * Reconstruct the optimal set of omitted events.
     * The problem states that if multiple optimal solutions exist,
     * priority is given to the one that leaves out (omits) the event with the highest index.
     * By backtracking from i = n down to 1, we decide on the highest indices first.
     * If omitting the current index allows us to reach the maximum value, we do so.
     */
    int curr_w = k;
    vector<bool> participated(n, true);
    for (int i = n; i >= 1; --i) {
        int idx = i - 1;
        // Check if taking this event into the 'omitted' set was possible and optimal
        if (curr_w >= m[idx] && dp[i][curr_w] == dp[i - 1][curr_w - m[idx]] + t[idx]) {
            participated[idx] = false;
            curr_w -= m[idx];
        }
    }

    // Calculate the final sadness and fear for the chosen set
    long long total_sadness = 0;
    int total_fear = 0;
    vector<int> p_indices;
    for (int i = 0; i < n; ++i) {
        if (participated[i]) {
            total_sadness += (long long)t[i];
            p_indices.push_back(i);
        } else {
            total_fear += m[i];
        }
    }

    // Output according to the specified format
    cout << total_sadness << " " << total_fear << "\n";
    for (int i = 0; i < (int)p_indices.size(); ++i) {
        cout << p_indices[i] << (i == (int)p_indices.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
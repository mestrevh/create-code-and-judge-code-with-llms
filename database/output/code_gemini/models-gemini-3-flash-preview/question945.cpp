/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Nota de História (History Grading)
 * Goal: Find the Longest Increasing Subsequence of student events' correct ranks.
 * Complexity: O(S * N^2) where S is the number of student responses and N is the number of events.
 * Given N <= 20, this is extremely efficient.
 */

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the number of events
    if (!(cin >> n)) return 0;

    // pos_correct[i] stores the correct rank of event i
    vector<int> pos_correct(n + 1);
    for (int i = 1; i <= n; ++i) {
        int r;
        if (cin >> r) {
            pos_correct[i] = r;
        }
    }

    int first_rank;
    // Read student responses until the end of input
    while (cin >> first_rank) {
        // pos_student[i] stores the rank student assigned to event i
        vector<int> pos_student(n + 1);
        pos_student[1] = first_rank;
        for (int i = 2; i <= n; ++i) {
            int r;
            if (cin >> r) {
                pos_student[i] = r;
            }
        }

        // event_at_rank_student[r] stores which event the student placed at rank r
        vector<int> event_at_rank_student(n + 1);
        for (int i = 1; i <= n; ++i) {
            event_at_rank_student[pos_student[i]] = i;
        }

        // A[r-1] will store the correct rank of the event that the student placed at rank r.
        // We want to find the Longest Increasing Subsequence of this array A.
        vector<int> A(n);
        for (int r = 1; r <= n; ++r) {
            A[r - 1] = pos_correct[event_at_rank_student[r]];
        }

        // Dynamic Programming approach for LIS (Longest Increasing Subsequence)
        // Time Complexity: O(N^2)
        vector<int> dp(n, 1);
        int max_lis = 0;
        if (n > 0) max_lis = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > max_lis) {
                max_lis = dp[i];
            }
        }

        // Output the result for the current student
        cout << max_lis << "\n";
    }

    return 0;
}
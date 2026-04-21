/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem CD - Competitive Programming Solution
 * 
 * Approach:
 * Given M <= 20, we can use a bitmask or recursion to explore all possible subsets 
 * of songs. 2^20 is approximately 10^6, which is efficient enough for a 1-second limit.
 * 
 * Logic:
 * 1. Read N (tape capacity) and M (number of songs).
 * 2. Iterate through all possible subsets using a bitmask (from 0 to 2^M - 1).
 * 3. Calculate the sum of durations for each subset.
 * 4. Keep track of the maximum sum that does not exceed N.
 * 5. If multiple subsets result in the same maximum sum, choose the one that is 
 *    lexicographically smaller when its elements are sorted (as per the "shorter duration" rule).
 * 6. Print the chosen durations in their original CD order, followed by the sum.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M) {
        vector<int> tracks(M);
        for (int i = 0; i < M; ++i) {
            cin >> tracks[i];
        }

        int best_sum = -1;
        int best_mask = 0;
        vector<int> best_sorted;

        // Iterate through every possible combination of songs
        for (int i = 0; i < (1 << M); ++i) {
            int current_sum = 0;
            // Calculate sum for current subset
            for (int j = 0; j < M; ++j) {
                if ((i >> j) & 1) {
                    current_sum += tracks[j];
                }
            }

            // Check if current subset is valid and potentially better
            if (current_sum <= N) {
                if (current_sum > best_sum) {
                    best_sum = current_sum;
                    best_mask = i;
                    best_sorted.clear();
                    for (int j = 0; j < M; ++j) {
                        if ((i >> j) & 1) best_sorted.push_back(tracks[j]);
                    }
                    sort(best_sorted.begin(), best_sorted.end());
                } else if (current_sum == best_sum && best_sum != -1) {
                    // Tie-breaker rule: lexicographical comparison of sorted durations
                    vector<int> current_subset;
                    for (int j = 0; j < M; ++j) {
                        if ((i >> j) & 1) current_subset.push_back(tracks[j]);
                    }
                    vector<int> current_sorted = current_subset;
                    sort(current_sorted.begin(), current_sorted.end());
                    
                    if (current_sorted < best_sorted) {
                        best_mask = i;
                        best_sorted = current_sorted;
                    }
                }
            }
        }

        // Print selected tracks in their original order
        for (int j = 0; j < M; ++j) {
            if ((best_mask >> j) & 1) {
                cout << tracks[j] << " ";
            }
        }
        cout << "sum:" << best_sum << "\n";
    }

    return 0;
}
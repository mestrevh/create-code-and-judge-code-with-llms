/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Sorvete (Ice Cream)
 * Goal: Merge overlapping or touching intervals to find covered areas of a beach.
 * Complexity: O(S log S) for sorting, O(S) for merging.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, S;
    // Read the beach length P and the number of ice cream sellers S
    if (!(cin >> P >> S)) return 0;

    // If there are no sellers, we output a blank line as per the specification
    if (S == 0) {
        cout << "\n";
        return 0;
    }

    // Read all intervals covered by the sellers
    vector<pair<int, int>> intervals(S);
    for (int i = 0; i < S; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // Sort intervals based on the starting point (U).
    // If starting points are equal, std::pair sorts by the second element (V).
    sort(intervals.begin(), intervals.end());

    // Merge logic
    int currentStart = intervals[0].first;
    int currentEnd = intervals[0].second;

    for (int i = 1; i < S; ++i) {
        // If the current interval starts before or exactly at the end of the previous one
        if (intervals[i].first <= currentEnd) {
            // Merge them by extending the end point if the new interval goes further
            if (intervals[i].second > currentEnd) {
                currentEnd = intervals[i].second;
            }
        } else {
            // No overlap/touch: output the finished merged interval and start a new one
            cout << currentStart << " " << currentEnd << "\n";
            currentStart = intervals[i].first;
            currentEnd = intervals[i].second;
        }
    }

    // Output the final merged interval
    cout << currentStart << " " << currentEnd << "\n";
    
    // As per the specification, indicate the end of the list with a blank line
    cout << "\n";

    return 0;
}
/**
 * Test Case 0:
 * Input:
 * 200 2
 * 0 21
 * 110 180
 * Output:
 * 0 21
 * 110 180
 * (blank line)
 *
 * Test Case 1:
 * Input:
 * 1000 3
 * 10 400
 * 80 200
 * 400 1000
 * Output:
 * 10 1000
 * (blank line)
 */
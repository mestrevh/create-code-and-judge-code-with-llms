/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Find elements that remain in the same position after sorting an array.
 * Complexity: O(N log N) for sorting, O(N) for comparison.
 * Constraints: N < 1000, 1 second time limit.
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> original(n);
    vector<int> sorted_arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> original[i];
        sorted_arr[i] = original[i];
    }

    // Sort the copy to compare positions
    sort(sorted_arr.begin(), sorted_arr.end());

    struct Match {
        int value;
        int position;
    };

    vector<Match> matches;
    for (int i = 0; i < n; ++i) {
        if (original[i] == sorted_arr[i]) {
            // Position is 1-based index
            matches.push_back({original[i], i + 1});
        }
    }

    // Output the count of matches
    cout << matches.size() << "\n";

    // Output each match: value and its 1-based position
    for (const auto& m : matches) {
        cout << m.value << " " << m.position << "\n";
    }

    return 0;
}
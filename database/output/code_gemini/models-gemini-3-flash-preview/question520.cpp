/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Competitive Programming Solution for "BoB"
 * Topic: Binary Search (std::equal_range)
 * Time Complexity: O(T * (N + Q log N))
 * Space Complexity: O(N)
 */

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    if (!(cin >> T)) return 0;

    // Pre-allocate memory to avoid repeated reallocations
    // Max N is 2^18 = 262,144
    vector<long long> A;
    A.reserve(262144);

    for (int t = 1; t <= T; ++t) {
        int N, Q;
        if (!(cin >> N >> Q)) break;

        // Read the ordered array A
        A.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Output case header as per format "caso C:"
        cout << "caso " << t << ":\n";

        // Process Q queries
        for (int i = 0; i < Q; ++i) {
            long long X;
            cin >> X;

            /* 
             * Since the array is sorted, we use binary search to find the 
             * range of elements equal to X. equal_range returns a pair of 
             * iterators representing the lower bound and upper bound.
             * The count is the distance between these iterators.
             * Time complexity: O(log N)
             */
            auto range = equal_range(A.begin(), A.end(), X);
            cout << (range.second - range.first) << "\n";
        }
    }

    return 0;
}
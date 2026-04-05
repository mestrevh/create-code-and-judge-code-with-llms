/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Ambrósio e a escolha dos números
 * Task: Select K numbers from N and maximize the total number of set bits (1's) in their binary representation.
 * Approach: Calculate bit count for each number, sort counts in descending order, and sum the top K.
 * Time Complexity: O(T * N log N)
 * Space Complexity: O(N)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N, K;
        if (!(cin >> N >> K)) break;

        vector<int> bit_counts;
        bit_counts.reserve(N);

        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            bit_counts.push_back(__builtin_popcount(val));
        }

        sort(bit_counts.begin(), bit_counts.end(), greater<int>());

        long long total_points = 0;
        int limit = min(K, N);
        for (int i = 0; i < limit; ++i) {
            total_points += bit_counts[i];
        }

        cout << total_points << "\n";
    }

    return 0;
}
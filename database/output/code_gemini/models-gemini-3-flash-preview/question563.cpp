/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/**
 * Problem: Subset Sum for prefixes of an array.
 * Given N elements and M queries (X, K).
 * Is there a subset of the first X elements that sums to K?
 * Constraints: T <= 50, N <= 100, M <= 1000, ai <= 1000, Ki <= 10^5.
 * Time Limit: 3s.
 * Solution: Dynamic Programming using bitsets for each prefix.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // dp[i] will store all possible sums using a subset of the first i elements.
        // Bit j is 1 if sum j is possible.
        // Max sum is N * max(ai) = 100 * 1000 = 100,000.
        static bitset<100001> dp[101];

        for (int i = 0; i <= N; ++i) dp[i].reset();
        
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] | (dp[i - 1] << A[i - 1]);
        }

        cout << "caso " << t << ":";
        for (int j = 0; j < M; ++j) {
            int X, K;
            cin >> X >> K;
            int result = 0;
            if (K >= 0 && K <= 100000) {
                if (dp[X][K]) result = 1;
            }
            cout << " " << result;
        }
        cout << "\n";
    }

    return 0;
}


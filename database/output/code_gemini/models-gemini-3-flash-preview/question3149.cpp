/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    // Each person must receive at least 1 sticker.
    // If N < M, it's impossible to satisfy this condition.
    if (N < M) {
        cout << 0 << endl;
        return 0;
    }

    // Let x_i be the number of stickers given to person i.
    // Constraints: 1 <= x_i <= K and sum(x_i) = N.
    // Let y_i = x_i - 1.
    // Constraints: 0 <= y_i <= K - 1 and sum(y_i) = N - M.
    int target = N - M;
    const int MOD = 1000000007;

    // dp[j] stores the number of ways to distribute stickers such that the sum is j.
    // We use space optimization to keep only the current distribution state.
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= M; ++i) {
        vector<long long> next_dp(target + 1, 0);
        vector<long long> pref(target + 1);
        
        // Build prefix sums of the current dp row to transition in O(target)
        pref[0] = dp[0];
        for (int j = 1; j <= target; ++j) {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }
        
        for (int j = 0; j <= target; ++j) {
            // Each person i can take between 0 and K-1 stickers (in the y_i transformation).
            // next_dp[j] = sum(dp[j-p]) for p in [0, K-1].
            // next_dp[j] = pref[j] - pref[j - K].
            long long val = pref[j];
            if (j >= K) {
                val = (val - pref[j - K] + MOD) % MOD;
            }
            next_dp[j] = val;
        }
        dp = next_dp;
    }

    // The result is the number of ways to have a sum of (N - M) with M people.
    cout << dp[target] << endl;

    return 0;
}
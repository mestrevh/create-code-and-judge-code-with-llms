/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: k-Tree
 * Path sum equals n, starting from root, with at least one edge weight >= d.
 * Edges have weights 1, 2, ..., k.
 * Approach: Dynamic Programming.
 * Result = (Ways to sum n using weights 1..k) - (Ways to sum n using weights 1..d-1).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, d;
    if (!(cin >> n >> k >> d)) return 0;

    const int MOD = 1000000007;

    auto count_ways = [&](int max_weight) {
        if (max_weight < 0) return 0LL;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= max_weight && j <= i; ++j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        return dp[n];
    };

    long long total_ways = count_ways(k);
    long long forbidden_ways = count_ways(d - 1);

    long long result = (total_ways - forbidden_ways + MOD) % MOD;
    cout << result << endl;

    return 0;
}


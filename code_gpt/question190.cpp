/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    
    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));

    for (long long i = 1; i <= K; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (long long j = 1; j <= N; ++j) {
        dp[1][j] = j;
    }

    for (long long i = 2; i <= K; ++i) {
        for (long long j = 2; j <= N; ++j) {
            dp[i][j] = LONG_LONG_MAX;
            for (long long x = 1; x <= j; ++x) {
                dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][x - 1], dp[i][j - x]));
            }
        }
    }

    cout << dp[K][N] << endl;
    return 0;
}

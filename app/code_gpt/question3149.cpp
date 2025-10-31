/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int l = 1; l <= K && l + j <= N; ++l) {
                dp[i][j + l] = (dp[i][j + l] + dp[i - 1][j]) % MOD;
            }
        }
    }
    
    int answer = 0;
    for (int j = 1; j <= N; ++j) {
        answer = (answer + dp[M][j]) % MOD;
    }

    cout << answer << endl;
    return 0;
}

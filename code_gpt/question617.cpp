/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long dp[5001][5001];

void precompute(int N) {
    for (int i = 0; i <= N; ++i) dp[i][0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int k = 1; k <= n; ++k) {
            dp[n][k] = (dp[n - 1][k] + dp[n][k - 1]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<int> K(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> K[i];
    }

    precompute(N);
    
    vector<long long> result(Q);
    for (int i = 0; i < Q; ++i) {
        result[i] = (K[i] > N ? dp[N][N] : dp[N][K[i]]) % MOD;
    }

    for (auto &res : result) {
        cout << res << ' ';
    }
    cout << '\n';
    return 0;
}

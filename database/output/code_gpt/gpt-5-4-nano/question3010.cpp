/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    const long long NEG = -(1LL << 60);
    vector<vector<long long>> dp(N, vector<long long>(M, NEG));

    auto coins = [&](char c) -> long long {
        if (c == 'o') return 1;
        if (c == '8') return 2;
        return 0;
    };

    dp[0][0] = (grid[0][0] == '|' ? NEG : coins(grid[0][0]));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '|') continue;
            if (i == 0 && j == 0) continue;

            long long best = NEG;
            if (i - 1 >= 0 && dp[i-1][j] != NEG) best = max(best, dp[i-1][j]);
            if (j - 1 >= 0 && dp[i][j-1] != NEG) best = max(best, dp[i][j-1]);
            if (best != NEG) dp[i][j] = best + coins(grid[i][j]);
        }
    }

    bool ok = dp[N-1][M-1] != NEG;
    cout << (ok ? "SIM\n" : "NAO\n");
    cout << "Valor maximo de moedas: " << (ok ? dp[N-1][M-1] : 0) << "\n";
    return 0;
}
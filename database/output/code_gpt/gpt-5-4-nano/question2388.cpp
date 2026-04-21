/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<int>> a(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    vector<int> dp(N + 1, 0);
    int best = 0;

    for (int i = 1; i <= N; i++) {
        int prevDiag = 0;
        for (int j = 1; j <= N; j++) {
            int temp = dp[j];
            if (a[i - 1][j - 1] == 1) {
                dp[j] = min({dp[j], dp[j - 1], prevDiag}) + 1;
                best = max(best, dp[j]);
            } else {
                dp[j] = 0;
            }
            prevDiag = temp;
        }
    }

    cout << best * best << "\n";
    return 0;
}
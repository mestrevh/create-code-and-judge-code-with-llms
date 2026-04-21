/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    if (!(cin >> N >> P)) return 0;

    vector<int> val(N), wt(N);
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++) cin >> wt[i];

    vector<long long> dp(P + 1, 0);
    for (int i = 0; i < N; i++) {
        int w = wt[i];
        int v = val[i];
        for (int cap = P; cap >= w; cap--) {
            dp[cap] = max(dp[cap], dp[cap - w] + v);
        }
    }

    cout << dp[P] << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q, D;
    if (!(cin >> Q >> D)) return 0;

    vector<long long> dp(D + 7, 0), ndp;
    dp[0] = 1;
    for (int step = 0; step < Q; step++) {
        ndp.assign(D + 7, 0);
        for (int pos = 0; pos <= D; pos++) {
            long long ways = dp[pos];
            if (!ways) continue;
            for (int dice = 1; dice <= 6; dice++) {
                int np = pos + dice;
                if (np > D) np = D + 1;
                ndp[np] += ways;
            }
        }
        dp.swap(ndp);
    }

    long long ans = dp[D] + dp[D + 1];
    cout << ans << "\n";
    return 0;
}
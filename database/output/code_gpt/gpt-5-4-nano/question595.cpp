/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int game = 1;
    while (true) {
        int n;
        if (!(cin >> n)) return 0;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

        auto sumRange = [&](int l, int r) -> long long { // inclusive l..r
            if (l > r) return 0LL;
            return pref[r + 1] - pref[l];
        };

        vector<long long> dp(n, 0), nxtdp(n, 0);

        for (int len = 1; len <= n; len++) {
            if (len == 1) {
                int i = 0;
                while (i + len - 1 < n) {
                    int l = i, r = i + len - 1;
                    bool turnFirst = ((n - len) % 2 == 0); // first player's turn when remaining parity matches start
                    long long d;
                    if (turnFirst) {
                        int pick = a[l];
                        d = pick;
                    } else {
                        int leftv = a[l], rightv = a[r];
                        int pick = (leftv >= rightv ? leftv : rightv);
                        d = -pick;
                    }
                    dp[l] = d;
                    i++;
                }
                continue;
            }
        }

        dp.assign(n, 0);
        for (int l = 0; l < n; l++) {
            int r = l;
            bool turnFirst = ((n - 1) % 2 == 0); // remaining len=1 => n-len parity
            // Turn when len=1: n-len = n-1; if even, first's turn.
            long long d;
            if (turnFirst) d = a[l];
            else d = -a[l];
            dp[l] = d;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                bool turnFirst = ((n - len) % 2 == 0);
                long long best;
                if (turnFirst) {
                    long long takeL = a[l] + (len - 1 >= 1 ? dp[l + 1] : 0);
                    long long takeR = a[r] + (len - 1 >= 1 ? dp[l] : 0); // dp[l] currently for len-1 at interval [l..r-1]
                    best = max(takeL, takeR);
                } else {
                    int leftv = a[l], rightv = a[r];
                    int pickVal;
                    if (leftv >= rightv) pickVal = leftv;
                    else pickVal = rightv;
                    long long follow;
                    if (leftv >= rightv) follow = dp[l + 1];
                    else follow = dp[l]; // interval [l+1..r] corresponds to dp[l] for previous len-1
                    best = -pickVal + follow;
                }
                nxtdp[l] = best;
            }
            dp.swap(nxtdp);
        }

        long long maxDiff = dp[0];
        long long p = llabs(maxDiff);
        cout << "In game " << game++ << ", the greedy strategy might lose by as many as " << p << " points.\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> f(N);
        for (int i = 0; i < N; i++) cin >> f[i];

        const int CAP = 480;
        vector<char> dp(CAP + 1, 0);
        dp[0] = 1;
        for (int x : f) {
            for (int s = CAP - x; s >= 0; --s) {
                if (dp[s]) dp[s + x] = 1;
            }
        }
        int ans = 0;
        for (int s = CAP; s >= 0; --s) {
            if (dp[s]) {
                ans = s;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
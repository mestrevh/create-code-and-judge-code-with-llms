/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int NBASE = 4;
    auto canPair = [](char a, char b) -> bool {
        return (a=='B' && b=='S') || (a=='S' && b=='B') || (a=='C' && b=='F') || (a=='F' && b=='C');
    };

    string s;
    while (true) {
        if (!getline(cin, s)) break;
        if (s == "Z") break;
        if (!s.empty() && (s.back()=='\r')) s.pop_back();

        int n = (int)s.size();
        vector<vector<short>> dp(n, vector<short>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                short best = dp[i][j-1];
                best = max<short>(best, dp[i+1][j]);
                if (canPair(s[i], s[j])) best = max<short>(best, (short)(dp[i+1][j-1] + 1));
                for (int k = i; k < j; ++k) {
                    best = max<short>(best, (short)(dp[i][k] + dp[k+1][j]));
                }
                dp[i][j] = best;
            }
        }

        cout << dp[0][n-1] << "\n";
    }
    return 0;
}
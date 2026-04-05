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
        vector<int> P(N), W(N);
        for (int i = 0; i < N; i++) cin >> P[i] >> W[i];

        int G;
        cin >> G;

        vector<int> people(G);
        int maxCap = 0;
        for (int i = 0; i < G; i++) {
            cin >> people[i];
            maxCap = max(maxCap, people[i]);
        }

        vector<long long> dp(maxCap + 1, 0);
        for (int i = 0; i < N; i++) {
            int wt = W[i], val = P[i];
            for (int c = maxCap; c >= wt; c--) {
                dp[c] = max(dp[c], dp[c - wt] + val);
            }
        }

        sort(people.begin(), people.end());
        long long ans = 0;
        for (int c : people) ans += dp[c];
        cout << ans << "\n";
    }
    return 0;
}
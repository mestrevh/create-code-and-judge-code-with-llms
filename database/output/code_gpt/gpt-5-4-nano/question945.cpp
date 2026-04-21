/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> c(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        pos[c[i]] = i;
    }

    int x;
    vector<int> a(n);
    bool firstOutput = true;
    while (true) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!(cin >> x)) {
                ok = false;
                break;
            }
            a[i] = pos[x];
        }
        if (!ok) break;

        vector<int> dp(n + 1, 0);
        int best = 0;
        for (int i = 0; i < n; i++) {
            int v = a[i];
            int val = 1;
            for (int j = 1; j < v; j++) {
                val = max(val, dp[j] + 1);
            }
            dp[v] = max(dp[v], val);
            best = max(best, val);
        }

        cout << best << "\n";
    }

    return 0;
}
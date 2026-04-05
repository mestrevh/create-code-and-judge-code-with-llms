/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        if (!getline(cin, line)) break;
        bool hasDigit = false;
        for (char c : line) if (isdigit((unsigned char)c) || c=='-' ) { hasDigit = true; break; }
        if (!hasDigit) continue;

        stringstream ss(line);
        int N, q;
        if (!(ss >> N >> q)) continue;

        vector<int> a(q);
        for (int i = 0; i < q; i++) ss >> a[i];

        vector<int> dp(N + 1, -1);
        vector<char> pre(N + 1, 0);
        vector<int> parent(N + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < q; i++) {
            int w = a[i];
            for (int s = N; s >= w; s--) {
                if (dp[s] == -1 && dp[s - w] != -1) {
                    dp[s] = dp[s - w] + 1;
                    pre[s] = 1;
                    parent[s] = s - w;
                }
            }
        }

        int bestS = 0;
        for (int s = 0; s <= N; s++) {
            if (dp[s] != -1) bestS = s;
        }

        vector<int> chosen;
        int cur = bestS;
        while (cur > 0 && dp[cur] != -1 && pre[cur]) {
            int prev = parent[cur];
            chosen.push_back(0);
            int usedLen = cur - prev;
            chosen.back() = usedLen;
            cur = prev;
        }

        vector<int> ans;
        for (int i = 0; i < (int)chosen.size(); i++) {
            int len = chosen[i];
            ans.push_back(len);
        }

        if (!ans.empty()) {
            reverse(ans.begin(), ans.end());
        }

        int sum = bestS;

        int idx = 0;
        for (int v : ans) {
            if (idx++) cout << ' ';
            cout << v;
        }
        if (!ans.empty()) cout << ' ';
        cout << "sum:" << sum;
        if (!cin.eof()) cout << "\n";
    }

    return 0;
}
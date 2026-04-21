/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while ( (cin >> n >> m) ) {
        if (n == 0 && m == 0) break;

        unordered_map<string, int> freq;
        freq.reserve((size_t)n * 2);

        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            auto it = freq.find(s);
            if (it == freq.end()) freq.emplace(s, 1);
            else it->second++;
        }

        vector<int> ans(n + 1, 0);
        for (const auto &p : freq) {
            int c = p.second;
            if (c >= 1 && c <= n) ans[c]++;
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
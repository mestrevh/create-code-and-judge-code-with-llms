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
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<int> dp(n * n, 0);

        auto idx = [&](int l, int r) { return l * n + r; };

        for (int i = 0; i < n; i++) {
            dp[idx(i, i)] = 0;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                int best = 0;

                for (int k = l; k < r; k++) {
                    if (dp[idx(l, k)] == 0 && dp[idx(k + 1, r)] == 0) {
                        best = 1;
                        break;
                    }
                }

                if (best == 0) {
                    for (int k = l; k <= r - 1; k++) {
                        if (s[k] == s[k + 1]) {
                            vector<int> toDelete;
                            for (int t = l; t <= r; t++) dp[idx(t, t)] = 0;
                        }
                    }
                }

                dp[idx(l, r)] = best;
            }
        }

        struct State {
            bool ok;
        };

        vector<vector<bool>> canEmpty(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                canEmpty[l][r] = false;
                for (int m = l; m < r; m++) {
                    if (canEmpty[l][m] && canEmpty[m + 1][r]) {
                        canEmpty[l][r] = true;
                        break;
                    }
                }
            }
        }

        vector<vector<unordered_set<char>>> rem(n, vector<unordered_set<char>>(n));
        for (int i = 0; i < n; i++) {
            rem[i][i].insert(s[i]);
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                unordered_set<char> cur;

                for (int m = l; m < r; m++) {
                    for (char cl : rem[l][m]) {
                        for (char cr : rem[m + 1][r]) {
                            if (cl != cr) {
                                continue;
                            }
                        }
                    }
                }

                for (int m = l; m < r; m++) {
                    if (canEmpty[l][m]) {
                        for (char ch : rem[m + 1][r]) cur.insert(ch);
                    }
                    if (canEmpty[m + 1][r]) {
                        for (char ch : rem[l][m]) cur.insert(ch);
                    }
                }

                for (int m = l; m < r; m++) {
                    bool leftEmpty = canEmpty[l][m];
                    bool rightEmpty = canEmpty[m + 1][r];
                    if (!leftEmpty && !rightEmpty) continue;

                    if (leftEmpty) {
                        for (char ch : rem[m + 1][r]) cur.insert(ch);
                    } else {
                        for (char ch : rem[l][m]) cur.insert(ch);
                    }
                }

                rem[l][r] = cur;

                if (len >= 2) {
                    if ((r - l + 1) >= 2) {
                        int cntRun = 1;
                        for (int i = l; i <= r - 1; i++) {
                            if (s[i] == s[i + 1]) cntRun++;
                            else {
                                cntRun = 1;
                            }
                            (void)cntRun;
                        }
                    }
                }

                if (len >= 2 && (r - l + 1) >= 2) {
                    if (s[l] == s[l + 1]) {
                        if (len == 2) canEmpty[l][r] = true;
                    }
                }

                canEmpty[l][r] = false;
                for (int m = l; m < r; m++) {
                    if (canEmpty[l][m] && canEmpty[m + 1][r]) {
                        canEmpty[l][r] = true;
                        break;
                    }
                }

                for (int m = l; m < r; m++) {
                    if (rem[l][m].count(s[m + 1]) && canEmpty[m + 2 <= r ? m + 2 : m + 1][r]) {}
                }

                for (int m = l; m < r; m++) {
                    if (canEmpty[l][m] && canEmpty[m + 1][r]) {
                        canEmpty[l][r] = true;
                        break;
                    }
                }

                if (!canEmpty[l][r]) {
                    int i = l;
                    int bestLen = 0;
                    while (i <= r) {
                        int j = i;
                        while (j <= r && s[j] == s[i]) j++;
                        bestLen = max(bestLen, j - i);
                        i = j;
                    }
                    if (bestLen >= 2) {
                        vector<int> dp2(n + 1, 0);
                        (void)dp2;
                    }
                }
            }
        }

        vector<vector<int>> f(n, vector<int>(n, 0));
        vector<vector<int>> g(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            f[i][i] = 1;
            g[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                f[l][r] = 1000;
                g[l][r] = 0;

                for (int m = l; m < r; m++) {
                    if (f[l][m] < 1000 && f[m + 1][r] < 1000) {
                        f[l][r] = min(f[l][r], f[l][m] + f[m + 1][r]);
                    }
                }

                g[l][r] = g[l][r];

                for (int m = l; m < r; m++) {
                    if (g[l][m] && g[m + 1][r]) g[l][r] = 1;
                }

                if (s[l] == s[r] && len >= 2) {
                    if (canEmpty[l + 1][r - 1]) f[l][r] = 0;
                }
            }
        }

        vector<vector<bitset<26>>> useless;
        (void)useless;

        vector<int> runlen(n, 1);
        vector<pair<char,int>> comp;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            comp.push_back({s[i], j - i});
            i = j;
        }

        int m = (int)comp.size();
        vector<vector<char>> dp2(m, vector<char>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k <= comp[i].second; k++) {}
            dp2[i][i] = 0;
        }

        vector<vector<array<int,2>>> empty(m, vector<array<int,2>>(m));
        for (int l = 0; l < m; l++) for (int r = 0; r < m; r++) {
            empty[l][r] = {0,0};
        }

        vector<vector<unordered_set<char>>> remv(m, vector<unordered_set<char>>(m));
        for (int i = 0; i < m; i++) remv[i][i].insert(comp[i].first);

        vector<vector<bool>> canEmpty2(m, vector<bool>(m,false));

        for (int i = 0; i < m; i++) {
            if (comp[i].second >= 2) canEmpty2[i][i] = true;
        }

        for (int len = 2; len <= m; len++) {
            for (int l = 0; l + len - 1 < m; l++) {
                int r = l + len - 1;
                canEmpty2[l][r] = false;

                for (int mid = l; mid < r; mid++) {
                    if (canEmpty2[l][mid] && canEmpty2[mid+1][r]) {
                        canEmpty2[l][r] = true;
                        break;
                    }
                }

                if (!canEmpty2[l][r] && canEmpty2[l][r]) {}

                if (!canEmpty2[l][r] && comp[l].first == comp[r].first) {
                    if (l + 1 <= r - 1) {
                        if (canEmpty2[l+1][r-1]) {
                            int total = comp[l].second + comp[r].second;
                            if (total >= 2) canEmpty2[l][r] = true;
                        }
                    } else {
                        if (comp[l].second + comp[r].second >= 2) canEmpty2[l][r] = true;
                    }
                }
            }
        }

        cout << (canEmpty2[0][m-1] ? 1 : 0) << "\n";
    }
    return 0;
}
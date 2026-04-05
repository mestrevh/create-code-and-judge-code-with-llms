/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string U;
    if (!(cin >> U)) return 0;

    int n = (int)U.size();
    vector<int> digits(n);
    for (int i = 0; i < n; i++) digits[i] = U[i] - '0';

    vector<int> cnt(10, 0);
    vector<int> best(n, 0);
    bool found = false;

    function<bool(int, int)> dfs = [&](int pos, int tight) -> bool {
        if (pos == n) return true;

        int curLimit = tight ? digits[pos] : 9;
        for (int d = curLimit; d >= 0; d--) {
            int ntight = (tight && d == curLimit) ? 1 : 0;
            if (pos == 0 && n > 1 && d == 0) {
                continue;
            }
            if (cnt[d] == 2) continue;
            cnt[d]++;
            best[pos] = d;
            bool ok = dfs(pos + 1, (tight && d == curLimit) ? 1 : 0);
            if (ok) return true;
            cnt[d]--;
        }
        return false;
    };

    bool ok = false;
    vector<int> prefix(n, 0);
    vector<int> rem(n, 0);

    function<bool(int, int)> solvePos = [&](int pos, int tight) -> bool {
        if (pos == n) return true;
        int limit = tight ? digits[pos] : 9;

        for (int d = limit; d >= 0; d--) {
            if (pos == 0 && n > 1 && d == 0) continue;
            if (cnt[d] >= 2) continue;
            int ntight = (tight && d == limit) ? 1 : 0;
            cnt[d]++;
            best[pos] = d;
            if (solvePos(pos + 1, ntight)) return true;
            cnt[d]--;
        }
        return false;
    };

    ok = solvePos(0, 1);

    if (!ok) {
        cout << 0 << "\n";
        return 0;
    }

    string out;
    out.reserve(n);
    for (int i = 0; i < n; i++) out.push_back(char('0' + best[i]));

    int idx = 0;
    while (idx + 1 < (int)out.size() && out[idx] == '0') idx++;
    out = out.substr(idx);

    cout << out << "\n";
    return 0;
}
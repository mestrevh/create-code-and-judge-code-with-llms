/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static array<long long,10> countDigitsUpTo(long long n) {
    array<long long,10> res{};
    if (n <= 0) {
        res.fill(0);
        return res;
    }

    string s = to_string(n);
    int L = (int)s.size();

    function<array<long long,10>(int,int,int)> dfs = [&](int pos, int tight, int started) -> array<long long,10> {
        if (pos == L) {
            array<long long,10> out{};
            out.fill(0);
            if (!started) return out;
            return out;
        }
        array<long long,10> total{};
        total.fill(0);

        int limit = tight ? (s[pos]-'0') : 9;
        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);
            int nstarted = started || (d != 0);
            auto sub = dfs(pos+1, ntight, nstarted);

            if (nstarted) {
                sub[d] += 1;
            }
            for (int k = 0; k < 10; k++) total[k] += sub[k];
        }
        return total;
    };

    res = dfs(0,1,0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        long long A, B;
        if (!(cin >> A >> B)) return 0;
        if (A == 0 && B == 0) break;
        auto cntB = countDigitsUpTo(B);
        auto cntA = countDigitsUpTo(A - 1);
        for (int i = 0; i < 10; i++) {
            long long ans = cntB[i] - cntA[i];
            if (i) cout << ' ';
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
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

    for (int tc = 0; tc < T; tc++) {
        int N, H;
        cin >> N >> H;

        vector<string> out;
        string cur(N, '0');

        function<void(int,int)> dfs = [&](int idx, int need) {
            if (need < 0) return;
            if (idx == N) {
                if (need == 0) out.push_back(cur);
                return;
            }
            int remaining = N - idx;
            if (need > remaining) return;

            if (need == remaining) {
                for (int i = idx; i < N; i++) cur[i] = '1';
                out.push_back(cur);
                for (int i = idx; i < N; i++) cur[i] = '0';
                return;
            }

            cur[idx] = '0';
            dfs(idx + 1, need);

            if (need > 0) {
                cur[idx] = '1';
                dfs(idx + 1, need - 1);
                cur[idx] = '0';
            }
        };

        dfs(0, H);

        for (auto &s : out) cout << s << "\n";
        if (tc != T - 1) cout << "\n";
    }

    return 0;
}
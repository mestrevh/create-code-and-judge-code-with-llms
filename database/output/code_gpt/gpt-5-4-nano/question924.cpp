/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> nxt(N + 1);
    for (int i = 1; i <= N; i++) cin >> nxt[i];

    vector<int> state(N + 1, 0);
    vector<int> memo(N + 1, 0);
    vector<int> vis(N + 1, 0);
    int iter = 1;

    function<int(int)> solve = [&](int u) -> int {
        if (memo[u] != 0) return memo[u];
        if (state[u] == 2) return memo[u];
        if (state[u] == 1) {
            int cur = u;
            int mx = cur;
            cur = nxt[cur];
            while (cur != u) {
                mx = max(mx, cur);
                cur = nxt[cur];
            }
            int v = u;
            do {
                memo[v] = mx;
                state[v] = 2;
                v = nxt[v];
            } while (v != u);
            return memo[u];
        }

        state[u] = 1;
        int v = nxt[u];
        int res = max(u, solve(v));
        memo[u] = res;
        state[u] = 2;
        return memo[u];
    };

    for (int i = 1; i <= N; i++) {
        if (memo[i] == 0) solve(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << memo[i] << "\n";
    }
    return 0;
}
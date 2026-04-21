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
    if (!(cin >> n >> m)) return 0;
    vector<long long> t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];

    vector<vector<int>> adj(n + 1);
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;
    vector<char> removed(n + 1, 0);
    vector<int> deg0(n + 1), removedDeg(n + 1, 0);

    long long totalRemovedAdj = 0;

    for (int i = 1; i <= n; i++) {
        deg0[i] = (int)adj[i].size();
    }

    for (int it = 0; it < n; it++) {
        int pick = -1;
        long long best = LLONG_MAX;
        for (int v = 1; v <= n; v++) {
            if (!removed[v]) {
                long long cost = t[v] * (long long)(deg0[v] - removedDeg[v]);
                if (cost < best) {
                    best = cost;
                    pick = v;
                }
            }
        }
        removed[pick] = 1;
        ans += t[pick] * (long long)(deg0[pick] - removedDeg[pick]);
        for (int u : adj[pick]) {
            if (!removed[u]) removedDeg[u]++;
        }
    }

    cout << ans << "\n";
    return 0;
}
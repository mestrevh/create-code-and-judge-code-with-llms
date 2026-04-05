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
    int s;
    cin >> s;

    vector<vector<int>> adj(n);
    int u, v;
    while (cin >> u >> v) {
        if (0 <= u && u < n && 0 <= v && v < n) adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }

    vector<char> vis(n, 0);
    vector<int> order;
    order.reserve(n);

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        order.push_back(u);
        for (int w : adj[u]) {
            if (!vis[w]) dfs(w);
        }
    };

    if (0 <= s && s < n) dfs(s);

    for (int x : order) cout << x << "\n";
    return 0;
}
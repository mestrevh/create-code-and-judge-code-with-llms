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

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        indeg[u]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) pq.push(i);
    }

    vector<int> order;
    order.reserve(n);

    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        order.push_back(v);
        for (int to : adj[v]) {
            if (--indeg[to] == 0) pq.push(to);
        }
    }

    if ((int)order.size() != n) {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << order[i];
    }
    return 0;
}
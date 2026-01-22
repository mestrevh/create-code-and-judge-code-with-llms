/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 7;

bool is_possible(const vector<pair<int, int>>& dominoes) {
    vector<int> degree(MAX, 0);
    vector<vector<int>> adj(MAX, vector<int>(MAX, 0));
    set<int> present;

    // Build adjacency and degree
    for (auto [a, b] : dominoes) {
        degree[a]++;
        degree[b]++;
        adj[a][b]++;
        adj[b][a]++;
        present.insert(a);
        present.insert(b);
    }

    // Check connectivity (BFS/DFS over present values)
    function<void(int, vector<bool>&)> dfs = [&](int u, vector<bool>& vis) {
        vis[u] = true;
        for (int v = 0; v < MAX; ++v) {
            if (adj[u][v] && !vis[v]) dfs(v, vis);
        }
    };
    vector<bool> vis(MAX, false);
    int start = *present.begin();
    dfs(start, vis);

    for (int x : present) {
        if (!vis[x]) return false;
    }

    // Count vertices with odd degree
    int odd_deg = 0;
    for (int i = 0; i < MAX; ++i)
        if (degree[i] % 2) ++odd_deg;

    // Eulerian path: 0 or 2 vertices with odd degree, and connected
    if (odd_deg == 0 || odd_deg == 2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<pair<int, int>> dom(N);
        for (int i = 0; i < N; ++i) {
            cin >> dom[i].first >> dom[i].second;
        }

        cout << "Teste " << test++ << '\n';
        cout << (is_possible(dom) ? "sim" : "nao") << '\n';
        cout << '\n';
    }
    return 0;
}

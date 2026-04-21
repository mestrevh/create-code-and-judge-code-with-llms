/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> C(N + 1);
    for (int i = 1; i <= N; i++) cin >> C[i];

    vector<vector<int>> posByVal(N/2 + 1);
    for (int i = 1; i <= N; i++) posByVal[C[i]].push_back(i);

    vector<vector<int>> g(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    int LOG = 1;
    while ((1 << LOG) <= N) LOG++;
    vector<vector<int>> up(LOG, vector<int>(N + 1, 0));
    vector<int> depth(N + 1, 0);

    int root = 1;
    vector<int> parent(N + 1, 0);
    vector<int> order;
    order.reserve(N);
    queue<int> q;
    q.push(root);
    parent[root] = root;
    depth[root] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (int to : g[v]) if (to != parent[v]) {
            parent[to] = v;
            depth[to] = depth[v] + 1;
            q.push(to);
        }
    }

    for (int v = 1; v <= N; v++) up[0][v] = parent[v];
    for (int j = 1; j < LOG; j++) {
        for (int v = 1; v <= N; v++) up[j][v] = up[j-1][ up[j-1][v] ];
    }

    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) if (diff & (1 << j)) a = up[j][a];
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return parent[a];
    };

    auto dist = [&](int a, int b) -> int {
        int L = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[L];
    };

    long long total = 0;
    for (int v = 1; v <= N/2; v++) {
        int a = posByVal[v][0];
        int b = posByVal[v][1];
        total += dist(a, b);
    }

    cout << total << "\n";
    return 0;
}
/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 50001;
const int LOGN = 17;

vector<int> adj[MAXN];
vector<int> card_positions[MAXN / 2 + 1];

int n;
int depth[MAXN];
int parent[MAXN][LOGN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void build_lca() {
    dfs(1, 0, 0);

    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != 0) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    for (int j = LOGN - 1; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = parent[u][j];
        }
    }

    if (u == v) {
        return u;
    }

    for (int j = LOGN - 1; j >= 0; --j) {
        if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }

    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        card_positions[c].push_back(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build_lca();

    long long total_score = 0;

    for (int i = 1; i <= n / 2; ++i) {
        int u = card_positions[i][0];
        int v = card_positions[i][1];
        
        int ancestor = lca(u, v);
        
        int distance = depth[u] + depth[v] - 2 * depth[ancestor];
        total_score += distance;
    }

    cout << total_score << "\n";

    return 0;
}

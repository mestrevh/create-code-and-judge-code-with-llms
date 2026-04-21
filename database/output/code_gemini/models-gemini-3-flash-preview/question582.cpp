/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 50005;
const int LOG = 17;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int card_pos[MAXN / 2 + 1][2];
int card_count[MAXN / 2 + 1];

void bfs(int root, int n) {
    for (int i = 1; i <= n; i++) {
        depth[i] = -1;
    }
    queue<int> q;
    q.push(root);
    depth[root] = 0;
    for (int i = 0; i < LOG; i++) {
        up[root][i] = root;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                q.push(v);
            }
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; i++) {
        int val;
        cin >> val;
        if (card_count[val] == 0) {
            card_pos[val][0] = i;
            card_count[val] = 1;
        } else {
            card_pos[val][1] = i;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, N);

    long long total_points = 0;
    for (int i = 1; i <= N / 2; i++) {
        int u = card_pos[i][0];
        int v = card_pos[i][1];
        int lca = get_lca(u, v);
        total_points += (1LL * depth[u] + depth[v] - 2LL * depth[lca]);
    }

    cout << total_points << "\n";

    return 0;
}
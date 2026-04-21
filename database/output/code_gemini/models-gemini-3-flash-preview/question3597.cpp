/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int MAXD = 505;

vector<int> adj[MAXN];
int sz[MAXN];
int dp[MAXN][MAXD];
int max_d[MAXN];
int q_bfs[MAXN];
int dist_bfs[MAXN];
int n, d;
long long total_dist = 0;
long long cnt_d = 0;

void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
        total_dist += (long long)sz[v] * (n - sz[v]);
    }
}

void dfs_dp(int u, int p) {
    dp[u][0] = 1;
    max_d[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_dp(v, u);
        int lim_v = min(max_d[v], d - 1);
        int lim_u = min(max_d[u], d);
        for (int k = 0; k <= lim_v; ++k) {
            int target = d - 1 - k;
            if (target >= 0 && target <= lim_u) {
                cnt_d += (long long)dp[u][target] * dp[v][k];
            }
        }
        for (int k = 0; k <= lim_v; ++k) {
            if (k + 1 <= d) {
                dp[u][k + 1] += dp[v][k];
            }
        }
        max_d[u] = max(max_d[u], max_d[v] + 1);
    }
}

int bfs(int start, int &farthest) {
    for (int i = 1; i <= n; ++i) dist_bfs[i] = -1;
    int head = 0, tail = 0;
    q_bfs[tail++] = start;
    dist_bfs[start] = 0;
    farthest = start;
    int max_dist = 0;
    while (head < tail) {
        int u = q_bfs[head++];
        if (dist_bfs[u] > max_dist) {
            max_dist = dist_bfs[u];
            farthest = u;
        }
        for (int v : adj[u]) {
            if (dist_bfs[v] == -1) {
                dist_bfs[v] = dist_bfs[u] + 1;
                q_bfs[tail++] = v;
            }
        }
    }
    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n)) return 0;
    if (n < 2) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int farthest_node;
    bfs(1, farthest_node);
    d = bfs(farthest_node, farthest_node);
    if (d == 0) {
        cout << 0 << "\n";
        return 0;
    }
    dfs_size(1, 0);
    dfs_dp(1, 0);
    long long ans = total_dist - (long long)cnt_d * d;
    cout << ans << "\n";
    return 0;
}
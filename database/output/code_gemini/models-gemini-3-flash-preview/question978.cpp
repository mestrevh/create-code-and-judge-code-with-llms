/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int get_dist(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve(int case_idx) {
    int n;
    if (!(cin >> n)) return;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    vector<vector<int>> dists(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dists[i][j] = get_dist(pts[i], pts[j]);
        }
    }

    // Solution A: Greedy (Nearest Neighbor)
    int resA = 0;
    vector<bool> visitedA(n, false);
    int current = 0;
    visitedA[0] = true;
    for (int i = 0; i < n - 1; i++) {
        int next = -1;
        int min_d = 2000000000;
        for (int j = 0; j < n; j++) {
            if (!visitedA[j]) {
                if (dists[current][j] < min_d) {
                    min_d = dists[current][j];
                    next = j;
                } else if (dists[current][j] == min_d) {
                    if (next == -1 || j < next) next = j;
                }
            }
        }
        resA += min_d;
        visitedA[next] = true;
        current = next;
    }
    resA += dists[current][0];

    // Solution B: Optimal TSP (using Bitmask DP)
    const int INF = 1000000000;
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] >= INF) continue;
            for (int v = 0; v < n; v++) {
                if (!(mask & (1 << v))) {
                    int next_mask = mask | (1 << v);
                    if (dp[next_mask][v] > dp[mask][u] + dists[u][v]) {
                        dp[next_mask][v] = dp[mask][u] + dists[u][v];
                    }
                }
            }
        }
    }
    int resB = INF;
    for (int i = 1; i < n; i++) {
        if (dp[(1 << n) - 1][i] != INF) {
            resB = min(resB, dp[(1 << n) - 1][i] + dists[i][0]);
        }
    }
    if (n == 0) resB = 0;

    // Solution C: MST + DFS
    vector<bool> inMST(n, false);
    vector<int> min_dist_mst(n, INF);
    vector<int> parent(n, -1);
    min_dist_mst[0] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                if (u == -1) u = v;
                else {
                    if (min_dist_mst[v] < min_dist_mst[u]) u = v;
                    else if (min_dist_mst[v] == min_dist_mst[u]) {
                        if (parent[v] < parent[u]) u = v;
                        else if (parent[v] == parent[u] && v < u) u = v;
                    }
                }
            }
        }
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int d = dists[u][v];
                if (d < min_dist_mst[v]) {
                    min_dist_mst[v] = d;
                    parent[v] = u;
                } else if (d == min_dist_mst[v]) {
                    if (u < parent[v]) parent[v] = u;
                }
            }
        }
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());

    vector<int> order;
    vector<bool> visC(n, false);
    auto dfs = [&](auto self, int u) -> void {
        visC[u] = true;
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visC[v]) self(self, v);
        }
    };
    dfs(dfs, 0);

    int resC = 0;
    for (int i = 0; i < n - 1; i++) {
        resC += dists[order[i]][order[i + 1]];
    }
    resC += dists[order[n - 1]][0];

    cout << case_idx << ": " << resA << " " << resB << " " << resC << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L;
    if (!(cin >> L)) return 0;
    for (int i = 0; i < L; i++) {
        solve(i);
    }
    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int N, M, L;
    if (!(cin >> N >> M >> L)) return;
    
    vector<int> V(N);
    for (int i = 0; i < N; ++i) cin >> V[i];
    
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) dist[i][i] = 0;
    
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if (u >= 0 && u < N && v >= 0 && v < N) {
            if (c < dist[u][v]) {
                dist[u][v] = dist[v][u] = c;
            }
        }
    }
    
    // Floyd-Warshall for all-pairs shortest paths
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Steiner Tree DP
    // dp[mask][i] is the minimum cost to connect the set of nodes in mask, with i being a vertex in the tree.
    vector<vector<int>> dp(1 << N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 0;
    }
    
    for (int mask = 1; mask < (1 << N); ++mask) {
        // Combination step: connect two sub-trees with a common node i
        for (int i = 0; i < N; ++i) {
            for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                if (dp[sub][i] != INF && dp[mask ^ sub][i] != INF) {
                    dp[mask][i] = min(dp[mask][i], dp[sub][i] + dp[mask ^ sub][i]);
                }
            }
        }
        // Relaxation step: update costs using shortest paths
        for (int i = 0; i < N; ++i) {
            if (dp[mask][i] == INF) continue;
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] != INF) {
                    dp[mask][j] = min(dp[mask][j], dp[mask][i] + dist[i][j]);
                }
            }
        }
    }
    
    int min_total_cost = INF;
    for (int mask = 1; mask < (1 << N); ++mask) {
        // We assume any tree includes the USA (node 0).
        // If node 0 is not in the mask, it is still the root of the distribution process.
        int mask_with_zero = mask | 1;
        int current_winners = 0;
        for (int i = 0; i < N; ++i) {
            if ((mask_with_zero >> i) & 1) {
                current_winners += V[i];
            }
        }
        
        if (current_winners >= L) {
            // dp[mask][0] is the min cost to connect all nodes in mask to node 0.
            if (dp[mask][0] < min_total_cost) {
                min_total_cost = dp[mask][0];
            }
        }
    }
    
    cout << min_total_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
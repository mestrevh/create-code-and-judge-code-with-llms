/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Competitive Programming Solution for "Amizade" (Largest Connected Component)
 * Utilizing Disjoint Set Union (DSU) with Path Compression and Union by Size.
 * Time Complexity: O(T * (N + M * alpha(N)))
 * Space Complexity: O(N)
 */

int find_set(int i, vector<int>& parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i], parent);
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    if (N <= 0) {
        cout << 0 << "\n";
        return;
    }

    // Initialize DSU structures
    vector<int> parent(N + 1);
    iota(parent.begin(), parent.end(), 0);
    vector<int> sz(N + 1, 1);
    int max_group = 1;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        
        // Basic validation - though problem constraints suggest valid input
        if (u < 1 || u > N || v < 1 || v > N) continue;

        int root_u = find_set(u, parent);
        int root_v = find_set(v, parent);

        if (root_u != root_v) {
            // Union by size to keep the tree flat
            if (sz[root_u] < sz[root_v]) swap(root_u, root_v);
            parent[root_v] = root_u;
            sz[root_u] += sz[root_v];
            
            // Update the maximum group size found so far
            if (sz[root_u] > max_group) {
                max_group = sz[root_u];
            }
        }
    }

    cout << max_group << "\n";
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read number of test cases
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}
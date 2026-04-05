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
 * Disjoint Set Union (DSU) structure to manage and merge categories of stones.
 * It uses path compression and union by size for optimal performance,
 * achieving nearly constant time per operation on average.
 */
struct DSU {
    vector<int> parent;
    vector<int> sz;
    int num_comp;
    int max_sz;

    // Initializes DSU with n stones, each in its own category.
    DSU(int n) : num_comp(n), max_sz(n > 0 ? 1 : 0) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    // Finds the representative of the category containing element i with path compression.
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    // Merges categories containing elements i and j, updating the component count and max size.
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Union by size
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            if (sz[root_i] > max_sz) max_sz = sz[root_i];
            num_comp--;
        }
    }
};

int main() {
    // Standard competitive programming I/O optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, N;
    int caseNum = 1;
    
    /**
     * Reads the number of stones (P) and the number of identical pairs (N).
     * The input format is P followed by N, then N pairs of stone identifiers.
     * The solution assumes no global "C" count is provided before the first P,
     * based on the provided test examples where P=5 and P=73 are the first numbers.
     */
    while (cin >> P >> N) {
        DSU dsu(P);
        for (int i = 0; i < N; ++i) {
            int u, v;
            if (!(cin >> u >> v)) break;
            
            // Check stone identifier bounds to ensure they belong to [0, P-1].
            if (u >= 0 && u < P && v >= 0 && v < P) {
                dsu.unite(u, v);
            }
        }
        
        // Output according to required format: "caso K: D M"
        // K = case number, D = number of distinct categories, M = max size of a category.
        cout << "caso " << caseNum << ": " << dsu.num_comp << " " << dsu.max_sz << "\n";
        caseNum++;
    }

    return 0;
}
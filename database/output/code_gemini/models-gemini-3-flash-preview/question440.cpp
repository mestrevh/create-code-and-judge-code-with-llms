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
 * Competitive Programming Solution for "Os Suspeitos" (The Suspects).
 * This problem asks for the size of the connected component containing student 0.
 * Using Disjoint Set Union (DSU) with path compression and union by size.
 */

struct DSU {
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }

    int size(int i) {
        return sz[find(i)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        DSU dsu(n);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            if (k > 0) {
                int first;
                cin >> first;
                for (int j = 1; j < k; ++j) {
                    int member;
                    cin >> member;
                    dsu.unite(first, member);
                }
            }
        }
        cout << dsu.size(0) << "\n";
    }

    return 0;
}
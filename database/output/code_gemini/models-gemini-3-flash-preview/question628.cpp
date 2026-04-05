/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

struct DSU {
    vector<int> parent;
    vector<int> rnk;
    DSU(int n) {
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rnk[root_i] < rnk[root_j]) {
                parent[root_i] = root_j;
            } else if (rnk[root_i] > rnk[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_i] = root_j;
                rnk[root_j]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        if (!(cin >> N >> M)) break;
        vector<Edge> edges(M);
        for (int i = 0; i < M; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        sort(edges.begin(), edges.end(), compareEdges);

        DSU dsu(N);
        long long total_weight = 0;
        int edges_added = 0;

        for (int i = 0; i < M; ++i) {
            if (dsu.unite(edges[i].u, edges[i].v)) {
                total_weight += (long long)edges[i].w;
                edges_added++;
                if (edges_added == N - 1) break;
            }
        }
        cout << total_weight << "\n";
    }

    return 0;
}
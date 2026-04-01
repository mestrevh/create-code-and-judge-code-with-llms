/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, c;
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.c < b.c;
    });

    DSU dsu(N);
    long long mst_weight = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.c;
            edges_count++;
            if (edges_count == N - 1) break;
        }
    }

    cout << mst_weight << endl;

    return 0;
}
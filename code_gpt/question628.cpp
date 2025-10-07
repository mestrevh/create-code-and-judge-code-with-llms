/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &e) const { return weight > e.weight; }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unionSets(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) swap(rootU, rootV);
            parent[rootV] = rootU;
            if (rank[rootU] == rank[rootV]) rank[rootU]++;
        }
    }
private:
    vector<int> parent, rank;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<Edge> edges(M);
        for (int i = 0; i < M; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
            edges[i].u--; edges[i].v--; // Zero-indexing
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(N);
        int totalWeight = 0;
        for (const auto &edge : edges) {
            if (uf.find(edge.u) != uf.find(edge.v)) {
                uf.unionSets(edge.u, edge.v);
                totalWeight += edge.weight;
            }
        }
        cout << totalWeight << endl;
    }
    return 0;
}

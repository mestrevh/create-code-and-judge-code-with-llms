/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}

struct DSU {
    std::vector<int> parent;
    std::vector<int> sz;
    DSU(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) {
                std::swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        }

        std::sort(edges.begin(), edges.end(), compareEdges);

        DSU dsu(n);
        long long max_weight = 0;
        int edges_count = 0;

        for (const auto& edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                max_weight += edge.weight;
                edges_count++;
                if (edges_count == n - 1) {
                    break;
                }
            }
        }
        std::cout << max_weight << std::endl;
    }

    return 0;
}

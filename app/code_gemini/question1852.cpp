/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

struct Edge {
    int u, v, w;
};

struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
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
            parent[root_i] = root_j;
        }
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    long long c, r;
    std::cin >> c >> r;

    std::vector<Edge> edges_mst(m);
    std::vector<std::vector<int>> adj_bfs(n);

    for (int i = 0; i < m; ++i) {
        int u, v, l;
        std::cin >> u >> v >> l;
        edges_mst[i] = {u, v, l};
        adj_bfs[u].push_back(v);
        adj_bfs[v].push_back(u);
    }

    std::sort(edges_mst.begin(), edges_mst.end(), compareEdges);

    DSU dsu(n);
    long long mst_total_length = 0;
    int edges_in_mst = 0;

    for (const auto& edge : edges_mst) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_total_length += edge.w;
            edges_in_mst++;
            if (edges_in_mst == n - 1) {
                break;
            }
        }
    }

    long long t1 = mst_total_length * c;

    std::vector<int> dist(n, -1);
    std::queue<int> q;
    long long total_path_links = 0;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj_bfs[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                total_path_links += dist[v];
                q.push(v);
            }
        }
    }

    long long t2 = total_path_links * r;

    std::cout << t1 << " " << t2 << std::endl;

    return 0;
}

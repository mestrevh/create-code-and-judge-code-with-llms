/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <limits>
#include <numeric>

struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
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
            parent[root_i] = root_j;
        }
    }
};

using Edge = std::tuple<int, int, int>;
using Graph = std::vector<std::vector<std::pair<int, int>>>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    Graph adj_original(N);
    std::vector<Edge> all_edges;
    all_edges.reserve(M);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj_original[u].push_back({v, w});
        adj_original[v].push_back({u, w});
        all_edges.emplace_back(w, u, v);
    }

    int S, D;
    std::cin >> S >> D;

    long long D1;
    {
        std::vector<long long> dist(N, std::numeric_limits<long long>::max());
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) {
                continue;
            }
            if (u == D) {
                break;
            }

            for (auto const& edge : adj_original[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != std::numeric_limits<long long>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        D1 = dist[D];
    }
    std::cout << D1 << "\n";

    std::sort(all_edges.begin(), all_edges.end());

    DSU dsu(N);
    Graph adj_mst(N);
    
    for (const auto& edge : all_edges) {
        int w, u, v;
        std::tie(w, u, v) = edge;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            adj_mst[u].push_back({v, w});
            adj_mst[v].push_back({u, w});
        }
    }

    long long D2 = 0;
    std::vector<int> path_costs;
    {
        std::vector<int> parent(N, -1);
        std::vector<int> edge_weight(N, 0);
        std::queue<int> q;

        q.push(S);
        parent[S] = S;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == D) {
                break;
            }

            for (auto const& edge : adj_mst[u]) {
                int v = edge.first;
                int w = edge.second;
                if (parent[v] == -1) {
                    parent[v] = u;
                    edge_weight[v] = w;
                    q.push(v);
                }
            }
        }

        int curr = D;
        while (curr != S) {
            path_costs.push_back(edge_weight[curr]);
            D2 += edge_weight[curr];
            curr = parent[curr];
        }
        std::reverse(path_costs.begin(), path_costs.end());
    }

    std::cout << D2 << "\n";
    std::cout << S;
    for (int cost : path_costs) {
        std::cout << " " << cost;
    }
    std::cout << " " << D << "\n";

    return 0;
}

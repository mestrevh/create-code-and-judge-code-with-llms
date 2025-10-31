/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
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

void solve() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    long long min_total_cost = LLONG_MAX;

    for (int mask = 0; mask < (1 << (N - 1)); ++mask) {
        vector<int> current_set;
        current_set.push_back(0);
        long long current_winners = V[0];

        for (int i = 0; i < N - 1; ++i) {
            if ((mask >> i) & 1) {
                current_set.push_back(i + 1);
                current_winners += V[i + 1];
            }
        }

        if (current_winners < L) {
            continue;
        }

        vector<Edge> complete_graph_edges;
        for (size_t i = 0; i < current_set.size(); ++i) {
            for (size_t j = i + 1; j < current_set.size(); ++j) {
                int u = current_set[i];
                int v = current_set[j];
                if (dist[u][v] != INF) {
                    complete_graph_edges.push_back({u, v, dist[u][v]});
                }
            }
        }
        
        sort(complete_graph_edges.begin(), complete_graph_edges.end(), compareEdges);
        
        DSU dsu(N);
        long long current_mst_cost = 0;
        
        for (const auto& edge : complete_graph_edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                current_mst_cost += edge.w;
            }
        }
        
        min_total_cost = min(min_total_cost, current_mst_cost);
    }
    
    cout << min_total_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

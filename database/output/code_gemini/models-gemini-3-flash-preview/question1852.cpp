/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int u, v;
    long long l;
    bool operator<(const Edge& other) const {
        return l < other.l;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    long long C, R;
    if (!(cin >> C >> R)) return 0;

    vector<Edge> edges(M);
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].l;
        adj[edges[i].u].push_back(edges[i].v);
        adj[edges[i].v].push_back(edges[i].u);
    }

    sort(edges.begin(), edges.end());
    DSU dsu(N);
    long long mst_weight_sum = 0;
    int edges_in_mst = 0;
    for (int i = 0; i < M && edges_in_mst < N - 1; ++i) {
        if (dsu.find(edges[i].u) != dsu.find(edges[i].v)) {
            dsu.unite(edges[i].u, edges[i].v);
            mst_weight_sum += edges[i].l;
            edges_in_mst++;
        }
    }
    long long T1 = mst_weight_sum * C;

    vector<int> dist(N, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    
    long long total_hops = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u != 0) {
            total_hops += dist[u];
        }
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    long long T2 = total_hops * R;

    cout << T1 << " " << T2 << endl;

    return 0;
}
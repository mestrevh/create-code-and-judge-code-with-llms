/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const ll INF_LL = 1e18;

struct Edge {
    int u, v, cost;
};

struct GraphEdge {
    int to;
    int cost;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.assign(n, 0);
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

    vector<vector<GraphEdge>> adj(N);
    vector<Edge> all_edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].cost;
        adj[all_edges[i].u].push_back({all_edges[i].v, all_edges[i].cost});
        adj[all_edges[i].v].push_back({all_edges[i].u, all_edges[i].cost});
    }

    int S, D;
    cin >> S >> D;

    // Dijkstra on the original graph for D1
    vector<ll> dist(N, INF_LL);
    dist[S] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            if (dist[u] + edge.cost < dist[edge.to]) {
                dist[edge.to] = (ll)dist[u] + edge.cost;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
    ll d1 = dist[D];

    // Kruskal's for the Minimum Spanning Tree
    sort(all_edges.begin(), all_edges.end(), compareEdges);
    DSU dsu(N);
    vector<vector<GraphEdge>> mst_adj(N);
    int edges_picked = 0;
    for (int i = 0; i < M && edges_picked < N - 1; ++i) {
        if (dsu.find(all_edges[i].u) != dsu.find(all_edges[i].v)) {
            dsu.unite(all_edges[i].u, all_edges[i].v);
            mst_adj[all_edges[i].u].push_back({all_edges[i].v, all_edges[i].cost});
            mst_adj[all_edges[i].v].push_back({all_edges[i].u, all_edges[i].cost});
            edges_picked++;
        }
    }

    // Path in the MST for D2 and route details
    vector<int> path_costs;
    vector<int> parent_node(N, -1);
    vector<int> edge_to_parent(N, 0);
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(S);
    visited[S] = true;

    bool found = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == D) {
            found = true;
            break;
        }
        for (auto& edge : mst_adj[u]) {
            if (!visited[edge.to]) {
                visited[edge.to] = true;
                parent_node[edge.to] = u;
                edge_to_parent[edge.to] = edge.cost;
                q.push(edge.to);
            }
        }
    }

    ll d2 = 0;
    if (found) {
        int curr = D;
        while (curr != S) {
            path_costs.push_back(edge_to_parent[curr]);
            d2 += edge_to_parent[curr];
            curr = parent_node[curr];
        }
        reverse(path_costs.begin(), path_costs.end());
    }

    cout << d1 << "\n";
    cout << d2 << "\n";
    cout << S;
    for (int cost : path_costs) {
        cout << " " << cost;
    }
    cout << " " << D << "\n";

    return 0;
}


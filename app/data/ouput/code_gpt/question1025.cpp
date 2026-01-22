/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, capacity, distance;
    Edge(int _v, int _capacity, int _distance) : v(_v), capacity(_capacity), distance(_distance) {}
};

vector<int> dijkstra_min_distance(int source, vector<vector<Edge>>& graph, int n) {
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > distance[u]) continue;
        for (auto& edge : graph[u]) {
            int v = edge.v, d = edge.distance;
            if (distance[u] + d < distance[v]) {
                distance[v] = distance[u] + d;
                pq.emplace(distance[v], v);
            }
        }
    }
    return distance;
}

int bfs_max_capacity(int source, int target, vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> capacity(n, 0);
    capacity[source] = INT_MAX;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& edge : graph[u]) {
            if (edge.capacity > 0) {
                capacity[edge.v] = max(capacity[edge.v], min(capacity[u], edge.capacity));
                q.push(edge.v);
            }
        }
    }
    return capacity[target];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> cities(k);
    for (int i = 0; i < k; ++i) {
        int loc;
        while (cin.peek() != '\n' && cin >> loc) {
            cities[i].push_back(loc);
        }
        cin.ignore();
    }

    int m;
    cin >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph[u].emplace_back(v, c, d);
        graph[v].emplace_back(u, c, d);
    }

    int s, t;
    cin >> s >> t;

    auto min_distances = dijkstra_min_distance(s, graph, n);
    int min_cost = min_distances[t];
    int max_capacity = bfs_max_capacity(s, t, graph);

    cout << min_cost << endl;
    cout << max_capacity << endl;

    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int d;
    int u;
    int p;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, V;
    if (!(cin >> C >> V)) return 0;

    vector<vector<Edge>> adj(C + 1);
    for (int i = 0; i < V; ++i) {
        int u, v, g;
        cin >> u >> v >> g;
        adj[u].push_back({v, g});
        adj[v].push_back({u, g});
    }

    vector<vector<int>> dist(C + 1, vector<int>(2, INF));
    priority_queue<Node> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.d > dist[curr.u][curr.p]) continue;

        for (const auto& e : adj[curr.u]) {
            int np = 1 - curr.p;
            if (dist[curr.u][curr.p] + e.weight < dist[e.to][np]) {
                dist[e.to][np] = dist[curr.u][curr.p] + e.weight;
                pq.push({dist[e.to][np], e.to, np});
            }
        }
    }

    if (dist[C][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[C][0] << endl;
    }

    return 0;
}
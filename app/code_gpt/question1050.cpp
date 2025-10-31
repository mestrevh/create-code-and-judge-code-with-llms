/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

class Graph {
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> size;
    int vertexCount;

public:
    Graph(int n) : vertexCount(n) {
        adj.resize(n);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    void addEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void contract(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        for (auto neighbor : adj[b]) {
            if (neighbor != a) {
                adj[a].push_back(neighbor);
                adj[neighbor].erase(remove(adj[neighbor].begin(), adj[neighbor].end(), b), adj[neighbor].end());
                adj[neighbor].push_back(a);
            }
        }

        adj[b].clear();
        parent[b] = a;
        size[a] += size[b];
        vertexCount--;
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    int distance(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;

        queue<int> q;
        vector<bool> visited(vertexCount, false);
        vector<int> dist(vertexCount, -1);
        q.push(a);
        visited[a] = true;
        dist[a] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[b];
    }

    int getVertexCount() {
        return vertexCount;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    int O;
    cin >> O;
    for (int i = 0; i < O; ++i) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == 'c') {
            g.contract(a, b);
            cout << g.getVertexCount() << endl;
        } else if (op == 'd') {
            cout << g.distance(a, b) << endl;
        }
    }

    return 0;
}

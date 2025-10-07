/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
};

vector<string> cidades;
vector<Edge> edges;
vector<vector<int>> adj, rev_adj;
bool visited[100];
int n, m;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

bool isCritical(Edge e) {
    memset(visited, false, sizeof(visited));
    int start = e.u;
    int end = e.v;

    for (int i = 0; i < n; ++i) {
        if (i != start && i != end) {
            visited[i] = true;
        }
    }

    dfs(start);

    if (!visited[end]) return true;

    memset(visited, false, sizeof(visited));
    dfs(end);

    return !visited[start];
}

int main() {
    while (cin >> n >> m, n || m) {
        cidades.resize(n);
        edges.clear();
        adj.assign(n, vector<int>());
        rev_adj.assign(n, vector<int());

        for (int i = 0; i < n; i++) {
            cin >> cidades[i];
        }
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;

            int idx_u = find(cidades.begin(), cidades.end(), u) - cidades.begin();
            int idx_v = find(cidades.begin(), cidades.end(), v) - cidades.begin();

            edges.push_back({idx_u, idx_v});
            adj[idx_u].push_back(idx_v);
            rev_adj[idx_v].push_back(idx_u);
        }

        vector<Edge> critical_edges;
        for (Edge e : edges) {
            if (isCritical(e)) {
                critical_edges.push_back(e);
            }
        }

        if (critical_edges.empty()) {
            cout << "Nenhuma\n";
        } else {
            for (Edge e : critical_edges) {
                cout << cidades[e.u] << " " << cidades[e.v] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

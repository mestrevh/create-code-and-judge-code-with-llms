/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005], rev[200005];
bool vis[200005];
set<int> nodes, edges_set;
set<pair<int, int>> edges;
int n, e, start, end;

void dfs(int v) {
    vis[v] = true;
    nodes.insert(v);
    for (int u : adj[v]) {
        if (!vis[u]) dfs(u);
        edges_set.insert({v, u});
    }
}

void find_cycles(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) find_cycles(u);
        else if (nodes.count(u)) {
            for (auto edge : edges_set) {
                edges.insert(edge);
            }
        }
    }
}

int main() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.insert({u, v});
    }
    cin >> start >> end;

    memset(vis, false, sizeof(vis));
    dfs(start);
    memset(vis, false, sizeof(vis));
    find_cycles(end);

    cout << "Nodes set:\n";
    for (int node : nodes) cout << node << "\n";
    cout << "Edges set:\n";
    for (auto edge : edges) cout << "(" << edge.first << ", " << edge.second << ")\n";
    
    return 0;
}

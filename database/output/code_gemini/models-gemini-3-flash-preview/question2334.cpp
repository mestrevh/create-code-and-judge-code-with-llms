/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    map<string, int> name_to_id;
    for (int i = 0; i < n; ++i) {
        string name;
        if (!(cin >> name)) break;
        name_to_id[name] = i;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        if (!(cin >> u >> v)) break;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
        }
    }

    string start_name, end_name;
    if (!(cin >> start_name >> end_name)) return 0;

    if (name_to_id.find(start_name) == name_to_id.end() || 
        name_to_id.find(end_name) == name_to_id.end()) {
        cout << "Mentira, nenhum filme da Disney da errado, nunca." << endl;
        return 0;
    }

    int start_node = name_to_id[start_name];
    int end_node = name_to_id[end_name];

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    bool found = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end_node) {
            found = true;
            break;
        }

        for (int v : adj[u]) {
            if (v >= 0 && v < n && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if (found) {
        cout << "We're all in this together!" << endl;
    } else {
        cout << "Mentira, nenhum filme da Disney da errado, nunca." << endl;
    }

    return 0;
}
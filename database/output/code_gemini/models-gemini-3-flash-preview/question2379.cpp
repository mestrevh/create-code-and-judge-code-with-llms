/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int start;
    if (!(cin >> start)) return 0;

    vector<vector<int>> adj(n);
    int u, v;
    while (cin >> u >> v) {
        if (u >= 0 && u < n) {
            adj[u].push_back(v);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!adj[i].empty()) {
            sort(adj[i].begin(), adj[i].end(), greater<int>());
        }
    }

    vector<bool> visited(n, false);
    queue<int> q;

    if (start >= 0 && start < n) {
        visited[start] = true;
        q.push(start);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << "\n";

        for (int neighbor : adj[curr]) {
            if (neighbor >= 0 && neighbor < n && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
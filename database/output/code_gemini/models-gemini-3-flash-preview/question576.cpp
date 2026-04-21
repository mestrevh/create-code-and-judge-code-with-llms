/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        int e;
        cin >> e;
        vector<vector<int>> adj(n);
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            if (u >= 0 && u < n && v >= 0 && v < n) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<int> color(n, -1);
        bool possible = true;
        
        // Since the graph is strongly connected, one BFS starting from node 0 is enough
        queue<int> q;
        color[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
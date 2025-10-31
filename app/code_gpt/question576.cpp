/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int n, const vector<vector<int>>& graph) {
    vector<int> color(n, -1);
    queue<int> q;
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            color[start] = 0;
            q.push(start);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, e;
    while (cin >> n, n) {
        cin >> e;
        vector<vector<int>> graph(n);
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout << (isBipartite(n, graph) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
    return 0;
}

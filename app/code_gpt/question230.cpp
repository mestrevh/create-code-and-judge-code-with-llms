/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int longest_path;

void dfs(int node, int path_length) {
    longest_path = max(longest_path, path_length);
    for (int neighbor : graph[node]) {
        dfs(neighbor, path_length + 1);
    }
}

int main() {
    int n, m;

    while (cin >> n >> m, n || m) {
        graph.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        longest_path = 0;
        for (int i = 0; i < n; i++) {
            visited.assign(n, false);
            dfs(i, 0);
        }
        
        cout << longest_path << endl;
    }
    return 0;
}

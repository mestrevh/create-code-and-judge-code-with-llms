/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> s;
    s.push(v);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            cout << node << endl;
        
            for (int i = graph[node].size() - 1; i >= 0; --i) {
                if (!visited[graph[node][i]]) {
                    s.push(graph[node][i]);
                }
            }
        }
    }
}

int main() {
    int n, start;
    cin >> n >> start;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    string line;
    cin.ignore();

    while (getline(cin, line)) {
        int u, v;
        stringstream ss(line);
        ss >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(start, graph, visited);

    return 0;
}

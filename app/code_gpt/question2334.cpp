/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

bool dfs(int current, int target, vector<vector<int>>& graph, vector<bool>& visited) {
    if (current == target) return true;
    visited[current] = true;
    for (int neighbor : graph[current]) {
        if (!visited[neighbor] && dfs(neighbor, target, graph, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    unordered_map<string, int> nameToIndex;
    vector<string> names(n);
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i) {
        getline(cin, names[i]);
        nameToIndex[names[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    string startName, endName;
    cin >> ws;
    getline(cin, startName);
    getline(cin, endName);

    int start = nameToIndex[startName];
    int end = nameToIndex[endName];

    vector<bool> visited(n, false);
    if (dfs(start, end, graph, visited)) {
        cout << "We're all in this together!" << endl;
    } else {
        cout << "Mentira, nenhum filme da Disney da errado, nunca." << endl;
    }

    return 0;
}

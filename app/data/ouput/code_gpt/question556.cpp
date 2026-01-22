/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<bool> inStack;

bool dfs(int v, int parent) {
    visited[v] = true;
    inStack[v] = true;

    for(int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, v))
                return true;
        } else if (neighbor != parent && inStack[neighbor]) {
            return true;
        }
    }
    
    inStack[v] = false;
    return false;
}

bool hasCycle(int N) {
    visited.assign(N, false);
    inStack.assign(N, false);
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    string line;
    int caseNumber = 0;

    while (true) {
        if (!getline(cin, line) || line.empty())
            break;
        
        stringstream ss(line);
        int N, M;
        ss >> N >> M;

        graph.assign(N, vector<int>());
        
        for (int i = 0; i < M; i++) {
            int u, v;
            getline(cin, line);
            stringstream edgeStream(line);
            edgeStream >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        caseNumber++;
        cout << caseNumber << " " << (hasCycle(N) ? 1 : 0) << endl;

        // Leitura da linha em branco
        getline(cin, line);
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void removeLeaves(map<string, vector<string>>& graph, set<string>& allNodes) {
    set<string> leaves;
    for (auto& [node, edges] : graph) {
        if (edges.empty()) leaves.insert(node);
    }
    for (const string& leaf : leaves) {
        cout << leaf << endl;
        allNodes.erase(leaf);
        graph.erase(leaf);
        for (auto& [node, edges] : graph) {
            edges.erase(remove(edges.begin(), edges.end(), leaf), edges.end());
        }
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        map<string, vector<string>> graph;
        set<string> allNodes;

        for (int i = 0; i < n; ++i) {
            stringstream ss(line);
            string A, B;
            ss >> A >> B;
            graph[A].push_back(B);
            allNodes.insert(A);
            allNodes.insert(B);
            getline(cin, line);
        }
        
        while (!graph.empty()) {
            removeLeaves(graph, allNodes);
            graph.erase(remove_if(graph.begin(), graph.end(), [](const auto& pair) {
                return pair.second.empty();
            }), graph.end());
        }
        
        for (const string& node : allNodes) {
            cout << node << endl;
        }
    }
    return 0;
}

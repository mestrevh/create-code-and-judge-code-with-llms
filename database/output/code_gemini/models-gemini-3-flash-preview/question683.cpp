/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        map<string, int> out_deg;
        map<string, vector<string>> parents;
        set<string> active_nodes;

        for (int i = 0; i < n; ++i) {
            string u, v;
            cin >> u >> v;
            active_nodes.insert(u);
            active_nodes.insert(v);
            
            // Increment out-degree of parent
            out_deg[u]++;
            
            // Ensure child node exists in the out-degree map
            if (out_deg.find(v) == out_deg.end()) {
                out_deg[v] = 0;
            }
            
            // Track reverse relationship to update out-degree upon removal
            parents[v].push_back(u);
        }

        while (!active_nodes.empty()) {
            vector<string> current_leaves;
            
            // Identify all nodes that currently have an out-degree of 0
            for (const string& node : active_nodes) {
                if (out_deg[node] == 0) {
                    current_leaves.push_back(node);
                }
            }

            // Sort current generation of leaves lexicographically
            sort(current_leaves.begin(), current_leaves.end());

            // Process each leaf: print, remove from graph, and update parents
            for (const string& leaf : current_leaves) {
                cout << leaf << "\n";
                active_nodes.erase(leaf);
                
                if (parents.count(leaf)) {
                    for (const string& p : parents[leaf]) {
                        out_deg[p]--;
                    }
                }
            }
        }
    }

    return 0;
}
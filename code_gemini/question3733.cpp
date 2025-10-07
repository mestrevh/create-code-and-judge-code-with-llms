/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

map<char, vector<char>> adj;
char start_node, goal_node;
map<char, bool> visited;

bool dfs(char u, char p, const string& context) {
    visited[u] = true;

    string my_output;
    if (p == '\0' || p == start_node) {
        my_output = string(1, u);
    } else {
        my_output = string(1, u);
        if (!context.empty()) {
            my_output += " " + context;
        }
    }
    cout << my_output << endl;

    if (u == goal_node) {
        return true;
    }

    if (adj.count(u)) {
        auto& neighbors = adj.at(u);
        for (size_t i = 0; i < neighbors.size(); ++i) {
            char v = neighbors[i];
            if (!visited[v]) {
                stringstream ss_context;
                bool first_sibling = true;
                for (size_t j = i + 1; j < neighbors.size(); ++j) {
                    if (!visited[neighbors[j]]) {
                        if (!first_sibling) {
                            ss_context << " ";
                        }
                        ss_context << neighbors[j];
                        first_sibling = false;
                    }
                }

                string context_for_v = ss_context.str();
                if (!context_for_v.empty()) {
                    context_for_v += " ";
                }
                context_for_v += my_output;

                if (dfs(v, u, context_for_v)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    set<char> all_nodes;

    if (!getline(cin, line) || line.empty()) return 1;
    start_node = line[0];

    if (!getline(cin, line) || line.empty()) return 1;
    goal_node = line[0];

    while (getline(cin, line) && !line.empty()) {
        if (line.length() < 5) continue;
        char u = line[0];
        char v = line[3];
        
        adj[u].push_back(v);
        all_nodes.insert(u);
        all_nodes.insert(v);
    }

    for (auto const& node : all_nodes) {
        if (adj.count(node)) {
            sort(adj[node].begin(), adj[node].end());
        }
        visited[node] = false;
    }

    dfs(start_node, '\0', "");
    
    cout << endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

void solve(int n) {
    if (n == 0) {
        return;
    }

    std::map<std::string, int> name_to_id;
    std::vector<std::string> id_to_name;
    int next_id = 0;

    auto get_id = [&](const std::string& name) {
        if (name_to_id.find(name) == name_to_id.end()) {
            name_to_id[name] = next_id;
            id_to_name.push_back(name);
            next_id++;
        }
        return name_to_id[name];
    };

    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        std::string u_name, v_name;
        std::cin >> u_name >> v_name;
        edges.push_back({get_id(u_name), get_id(v_name)});
    }

    int total_nodes = next_id;
    if (total_nodes == 0) {
        return;
    }

    std::vector<int> out_degree(total_nodes, 0);
    std::vector<std::vector<int>> rev_adj(total_nodes);

    for (const auto& edge : edges) {
        out_degree[edge.first]++;
        rev_adj[edge.second].push_back(edge.first);
    }

    int removed_count = 0;
    while (removed_count < total_nodes) {
        std::vector<std::string> current_leaves;
        for (int i = 0; i < total_nodes; ++i) {
            if (out_degree[i] == 0) {
                current_leaves.push_back(id_to_name[i]);
            }
        }

        std::sort(current_leaves.begin(), current_leaves.end());

        for (const auto& leaf_name : current_leaves) {
            std::cout << leaf_name << "\n";
            int leaf_id = name_to_id[leaf_name];

            out_degree[leaf_id] = -1; // Mark as removed
            removed_count++;

            for (int parent_id : rev_adj[leaf_id]) {
                if (out_degree[parent_id] > 0) {
                    out_degree[parent_id]--;
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n) {
        solve(n);
    }
    return 0;
}

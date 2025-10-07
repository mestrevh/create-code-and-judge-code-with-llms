/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

bool can_reach(int current, int target, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    if (current == target) {
        return true;
    }

    visited[current] = true;

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (can_reach(neighbor, target, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::map<std::string, int> name_to_id;
    std::vector<std::string> id_to_name(n);
    std::string name;

    for (int i = 0; i < n; ++i) {
        std::cin >> name;
        name_to_id[name] = i;
        id_to_name[i] = name;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    std::string start_name, end_name;
    std::cin >> start_name >> end_name;

    int start_id = name_to_id[start_name];
    int end_id = name_to_id[end_name];

    std::vector<bool> visited(n, false);

    if (can_reach(start_id, end_id, adj, visited)) {
        std::cout << "We're all in this together!" << std::endl;
    } else {
        std::cout << "Mentira, nenhum filme da Disney da errado, nunca." << std::endl;
    }

    return 0;
}

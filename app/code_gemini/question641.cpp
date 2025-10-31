/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>

void solve(int n, int m) {
    std::map<std::string, int> name_to_id;
    std::vector<std::pair<int, int>> edges_by_id;
    std::vector<std::pair<std::string, std::string>> edges_by_name;

    for (int i = 0; i < n; ++i) {
        std::string city_name;
        std::cin >> city_name;
        name_to_id[city_name] = i;
    }

    for (int i = 0; i < m; ++i) {
        std::string u_name, v_name;
        std::cin >> u_name >> v_name;
        edges_by_id.push_back({name_to_id[u_name], name_to_id[v_name]});
        edges_by_name.push_back({u_name, v_name});
    }

    std::vector<std::pair<std::string, std::string>> critical_edges;

    for (int i = 0; i < m; ++i) {
        std::vector<std::vector<int>> rev_adj(n);
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            int u = edges_by_id[j].first;
            int v = edges_by_id[j].second;
            rev_adj[v].push_back(u);
        }

        std::queue<int> q;
        std::vector<bool> visited(n, false);
        int count = 0;
        int capital_id = 0;

        q.push(capital_id);
        visited[capital_id] = true;
        count++;

        while (!q.empty()) {
            int current_node = q.front();
            q.pop();

            for (int neighbor : rev_adj[current_node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    count++;
                }
            }
        }

        if (count < n) {
            critical_edges.push_back(edges_by_name[i]);
        }
    }

    if (critical_edges.empty()) {
        std::cout << "Nenhuma" << std::endl;
    } else {
        for (const auto& edge : critical_edges) {
            std::cout << edge.first << " " << edge.second << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    bool first_case = true;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        if (!first_case) {
            std::cout << std::endl;
        }
        first_case = false;
        solve(n, m);
    }

    return 0;
}

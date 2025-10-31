/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

long long count_paths(int u, int dest, std::vector<std::vector<int>>& adj, std::vector<long long>& dp) {
    if (u == dest) {
        return 1;
    }
    if (dp[u] != -1) {
        return dp[u];
    }

    long long paths = 0;
    for (int v : adj[u]) {
        paths += count_paths(v, dest, adj, dp);
    }

    return dp[u] = paths;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore();

    std::map<std::string, int> name_to_id;
    std::vector<std::vector<int>> adj;
    int next_id = 0;

    auto get_id = [&](const std::string& name) -> int {
        if (name_to_id.find(name) == name_to_id.end()) {
            name_to_id[name] = next_id++;
            adj.resize(next_id);
        }
        return name_to_id[name];
    };

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);

        std::string source_name;
        ss >> source_name;
        if (source_name.empty()) {
            continue;
        }
        int u = get_id(source_name);

        std::string dest_name;
        while (ss >> dest_name) {
            int v = get_id(dest_name);
            adj[u].push_back(v);
        }
    }

    std::string start_name, end_name;
    std::cin >> start_name >> end_name;

    int start_node = get_id(start_name);
    int end_node = get_id(end_name);

    std::vector<long long> dp(next_id, -1);

    long long result = count_paths(start_node, end_node, adj, dp);

    std::cout << result << std::endl;

    return 0;
}

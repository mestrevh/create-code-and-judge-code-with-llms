/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

std::map<std::string, int> name_to_id;
std::vector<std::string> id_to_name;
std::vector<std::vector<int>> adj;
int next_id = 0;

int get_id(const std::string& name) {
    if (name_to_id.find(name) == name_to_id.end()) {
        name_to_id[name] = next_id;
        id_to_name.push_back(name);
        adj.push_back({});
        return next_id++;
    }
    return name_to_id[name];
}

std::pair<int, int> bfs(int start_node, int num_nodes) {
    std::vector<int> dist(num_nodes, -1);
    std::queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farthest_node, max_dist};
}

void mark_component_visited(int start_node, std::vector<bool>& visited) {
    std::queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string p_name, f_name;
        std::cin >> p_name >> f_name;
        int p_id = get_id(p_name);
        int f_id = get_id(f_name);
        adj[p_id].push_back(f_id);
        adj[f_id].push_back(p_id);
    }

    int num_people = next_id;
    if (num_people < 2) {
        return 0;
    }

    int max_diameter = -1;
    int res_u = -1, res_v = -1;
    std::vector<bool> visited(num_people, false);

    for (int i = 0; i < num_people; ++i) {
        if (!visited[i]) {
            std::pair<int, int> endpoint1_info = bfs(i, num_people);
            int u = endpoint1_info.first;

            std::pair<int, int> diameter_info = bfs(u, num_people);
            int v = diameter_info.first;
            int current_diameter = diameter_info.second;

            if (current_diameter > max_diameter) {
                max_diameter = current_diameter;
                res_u = u;
                res_v = v;
            }
            
            mark_component_visited(i, visited);
        }
    }

    std::string name1 = id_to_name[res_u];
    std::string name2 = id_to_name[res_v];

    if (name1 > name2) {
        std::swap(name1, name2);
    }

    std::cout << name1 << " " << name2 << " " << max_diameter << std::endl;

    return 0;
}

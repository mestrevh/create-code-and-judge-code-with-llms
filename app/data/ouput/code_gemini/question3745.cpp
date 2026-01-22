/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <deque>

struct Node {
    int f;
    int g;
    std::string city;
    std::string parent;

    bool operator<(const Node& other) const {
        if (f != other.f) {
            return f < other.f;
        }
        if (city != other.city) {
            return city < other.city;
        }
        return parent < other.parent;
    }
};

void print_pq(const std::multiset<Node>& pq) {
    std::cout << "[";
    bool first = true;
    for (const auto& node : pq) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << "['" << node.parent << "', '" << node.city << "', " << node.f << "]";
        first = false;
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string start_city, goal_city;
    std::cin >> start_city >> goal_city;

    std::map<std::string, int> heuristics;
    std::map<std::string, std::vector<std::pair<std::string, int>>> adj;

    std::string city;
    int h_val;
    while (std::cin >> city >> h_val) {
        heuristics[city] = h_val;
    }
    std::cin.clear();

    std::string s2;
    int w;
    std::cin >> s2 >> w;
    adj[city].push_back({s2, w});
    adj[s2].push_back({city, w});

    std::string s1_edge;
    while (std::cin >> s1_edge >> s2 >> w) {
        adj[s1_edge].push_back({s2, w});
        adj[s2].push_back({s1_edge, w});
    }

    std::multiset<Node> pq;
    std::map<std::string, int> g_costs;
    std::map<std::string, std::string> came_from;

    g_costs[start_city] = 0;
    pq.insert({heuristics[start_city], 0, start_city, ""});
    came_from[start_city] = start_city;

    while (!pq.empty()) {
        Node current = *pq.begin();
        pq.erase(pq.begin());

        if (current.city == goal_city) {
            break;
        }

        for (const auto& edge : adj[current.city]) {
            std::string neighbor_city = edge.first;
            int weight = edge.second;
            int new_g = current.g + weight;

            if (g_costs.find(neighbor_city) == g_costs.end() || new_g < g_costs[neighbor_city]) {
                g_costs[neighbor_city] = new_g;
                came_from[neighbor_city] = current.city;
                int new_f = new_g + heuristics[neighbor_city];
                pq.insert({new_f, new_g, neighbor_city, current.city});
            }
        }
        
        if (!pq.empty()) {
             print_pq(pq);
        }
    }
    
    std::cout << std::endl;

    std::deque<std::string> path;
    std::string current_path_node = goal_city;
    if (came_from.count(current_path_node)) {
        while (current_path_node != start_city) {
            path.push_front(current_path_node);
            current_path_node = came_from[current_path_node];
        }
    }
    path.push_front(start_city);

    bool first_node = true;
    for (const auto& node : path) {
        if (!first_node) {
            std::cout << " ";
        }
        std::cout << node;
        first_node = false;
    }
    std::cout << std::endl;

    return 0;
}

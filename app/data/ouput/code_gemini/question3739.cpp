/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

struct Node {
    string name;
    int heuristic;
};

bool compareNodes(const Node& a, const Node& b) {
    if (a.heuristic != b.heuristic) {
        return a.heuristic < b.heuristic;
    }
    return a.name < b.name;
}

void print_frontier(const vector<Node>& frontier) {
    cout << "[";
    for (size_t i = 0; i < frontier.size(); ++i) {
        cout << "['" << frontier[i].name << "', " << frontier[i].heuristic << "]";
        if (i < frontier.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start_node_name, goal_node_name;
    cin >> start_node_name >> goal_node_name;

    map<string, int> heuristics;
    string city_name;
    int h_value;

    string line;
    getline(cin, line); 

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        ss >> city_name >> h_value;
        heuristics[city_name] = h_value;
    }

    map<string, vector<string>> adj;
    string city1, city2;
    int cost;
    while (cin >> city1 >> city2 >> cost) {
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    vector<Node> frontier;
    map<string, bool> explored;
    map<string, string> parent;

    frontier.push_back({start_node_name, heuristics[start_node_name]});
    parent[start_node_name] = "";

    while (!frontier.empty()) {
        print_frontier(frontier);

        Node current = frontier[0];

        if (current.name == goal_node_name) {
            break;
        }

        frontier.erase(frontier.begin());
        explored[current.name] = true;

        vector<string>& neighbors = adj[current.name];
        sort(neighbors.begin(), neighbors.end());

        for (const string& neighbor_name : neighbors) {
            if (explored.count(neighbor_name)) {
                continue;
            }

            bool in_frontier = false;
            for (const auto& node : frontier) {
                if (node.name == neighbor_name) {
                    in_frontier = true;
                    break;
                }
            }
            if (in_frontier) {
                continue;
            }
            
            frontier.push_back({neighbor_name, heuristics[neighbor_name]});
            if (parent.find(neighbor_name) == parent.end()) {
                 parent[neighbor_name] = current.name;
            }
        }
        
        sort(frontier.begin(), frontier.end(), compareNodes);
    }

    vector<string> path;
    if (parent.count(goal_node_name)) {
        string current_path_node = parent[goal_node_name];
        while (!current_path_node.empty()) {
            path.push_back(current_path_node);
            current_path_node = parent[current_path_node];
        }
        reverse(path.begin(), path.end());
    }
    
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

void print_state(const map<char, int>& dist) {
    cout << "[";
    auto it = dist.begin();
    while (it != dist.end()) {
        cout << "(" << it->second << ", '" << it->first << "')";
        ++it;
        if (it != dist.end()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char start_node, goal_node;
    cin >> start_node >> goal_node;

    map<char, vector<pair<char, int>>> adj;
    char u_in, v_in;
    int w_in;
    string line;
    
    // Consume the rest of the line after reading goal_node
    getline(cin, line); 

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        if (ss >> u_in >> v_in >> w_in) {
            adj[u_in].push_back({v_in, w_in});
        }
    }

    priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, greater<tuple<int, int, char>>> pq;
    
    map<char, int> dist;
    map<char, char> parent;
    set<char> visited;
    int push_order = 0;

    dist[start_node] = 0;
    pq.push({0, -(push_order++), start_node});
    
    print_state(dist);

    while (!pq.empty()) {
        auto [current_cost, _, u_node] = pq.top();
        pq.pop();

        if (visited.count(u_node)) {
            continue;
        }
        visited.insert(u_node);
        
        bool dist_changed = false;
        
        if (adj.count(u_node)) {
            for (auto const& edge : adj[u_node]) {
                char v_node = edge.first;
                int weight = edge.second;
                int new_cost = current_cost + weight;

                if (dist.find(v_node) == dist.end() || new_cost < dist.at(v_node)) {
                    dist[v_node] = new_cost;
                    parent[v_node] = u_node;
                    pq.push({new_cost, -(push_order++), v_node});
                    dist_changed = true;
                }
            }
        }
        
        if (u_node == goal_node) {
            break;
        }
        
        if (dist_changed) {
             print_state(dist);
        }
    }

    vector<char> path;
    if (dist.count(goal_node)) {
        char current = goal_node;
        while (parent.count(current)) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(start_node);
        reverse(path.begin(), path.end());
    }

    cout << "['";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << "', '";
        }
    }
    cout << "']" << endl;

    return 0;
}

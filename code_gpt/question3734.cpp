/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, char> pii;

int main() {
    char start, goal;
    cin >> start >> goal;
    map<char, vector<pii>> graph;
    string line;
    getline(cin, line); // Consume the leftover newline

    while (getline(cin, line) && !line.empty()) {
        char x, y;
        int distance;
        sscanf(line.c_str(), "%c %c %d", &x, &y, &distance);
        graph[x].push_back({distance, y});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    map<char, int> distance_map;
    map<char, char> parent_map;
    set<char> visited;
    vector<char> path;

    pq.push({0, start});
    distance_map[start] = 0;

    while (!pq.empty()) {
        auto [dist, node] = pq.top(); pq.pop();
        visited.insert(node);
        
        vector<pii> current_queue(pq.begin(), pq.end());
        sort(current_queue.begin(), current_queue.end());
        cout << "[";
        for (size_t i = 0; i < current_queue.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << "(" << current_queue[i].first << ", '" << current_queue[i].second << "')";
        }
        cout << "]" << endl;

        for (const auto& [next_dist, neighbor] : graph[node]) {
            if (visited.count(neighbor)) continue;
            int new_dist = dist + next_dist;
            if (distance_map.find(neighbor) == distance_map.end() || new_dist < distance_map[neighbor]) {
                distance_map[neighbor] = new_dist;
                parent_map[neighbor] = node;
                pq.push({new_dist, neighbor});
            }
        }
    }

    char curr = goal;
    while (curr != start) {
        path.push_back(curr);
        curr = parent_map[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "[";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << "'" << path[i] << "'";
    }
    cout << "]" << endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main() {
    string start, goal, line;
    map<char, vector<pair<char, int>>> graph;
    
    getline(cin, start);
    getline(cin, goal);
    
    while (getline(cin, line) && !line.empty()) {
        char from = line[0], to = line[2];
        int distance = stoi(line.substr(4));
        graph[from].emplace_back(to, distance);
    }

    queue<char> q;
    set<char> visited;
    map<char, vector<char>> path;
    
    q.push(start[0]);
    visited.insert(start[0]);
    path[start[0]] = {start[0]};
    
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        
        vector<char> adj;
        for (auto& neighbor : graph[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first);
                q.push(neighbor.first);
                path[neighbor.first] = path[current];
                path[neighbor.first].push_back(neighbor.first);
                adj.push_back(neighbor.first);
            }
        }
        cout << current << "\n";
        for (char node : adj) {
            cout << node << " ";
        }
        cout << "\n";
    }

    if (visited.find(goal[0]) != visited.end()) {
        cout << "\n";
        for (char node : path[goal[0]]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}

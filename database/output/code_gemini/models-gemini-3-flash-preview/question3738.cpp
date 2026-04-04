/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start_str, goal_str;
    if (!getline(cin, start_str)) return 0;
    if (!getline(cin, goal_str)) return 0;

    if (start_str.empty() || goal_str.empty()) return 0;

    char start_node = start_str[0];
    char goal_node = goal_str[0];

    map<char, vector<char>> adj;
    string line;
    while (getline(cin, line) && !line.empty()) {
        char u, v;
        int d;
        if (sscanf(line.c_str(), " %c->%c %d", &u, &v, &d) >= 2) {
            adj[u].push_back(v);
        }
    }

    for (auto &p : adj) {
        sort(p.second.begin(), p.second.end());
        p.second.erase(unique(p.second.begin(), p.second.end()), p.second.end());
    }

    deque<char> q;
    map<char, bool> visited;
    map<char, char> parent;

    q.push_back(start_node);
    visited[start_node] = true;

    for (int i = 0; i < (int)q.size(); ++i) {
        cout << q[i] << " ";
    }
    cout << "\n";

    while (!q.empty()) {
        char u = q.front();
        q.pop_front();

        if (adj.count(u)) {
            for (char v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push_back(v);
                }
            }
        }

        if (!q.empty()) {
            for (int i = 0; i < (int)q.size(); ++i) {
                cout << q[i] << " ";
            }
            cout << "\n";
        }
    }

    cout << "\n";

    if (visited[goal_node]) {
        vector<char> path;
        char curr = goal_node;
        while (true) {
            path.push_back(curr);
            if (curr == start_node) break;
            if (parent.find(curr) == parent.end()) break;
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); ++i) {
            cout << path[i] << (i == (int)path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start, goal;
    if (!(cin >> start >> goal)) return 0;

    map<string, vector<string>> adj;
    string edge;
    while (cin >> edge) {
        size_t pos = edge.find("->");
        if (pos == string::npos) break;
        string u = edge.substr(0, pos);
        string v = edge.substr(pos + 2);
        int d;
        if (!(cin >> d)) break;
        adj[u].push_back(v);
    }

    deque<string> frontier;
    frontier.push_back(start);
    set<string> visited;
    visited.insert(start);

    while (!frontier.empty()) {
        for (size_t i = 0; i < frontier.size(); ++i) {
            cout << frontier[i] << (i == frontier.size() - 1 ? "" : " ");
        }
        cout << "\n";

        string curr = frontier.front();
        if (curr == goal) break;

        frontier.pop_front();

        vector<string> unvisited;
        if (adj.count(curr)) {
            for (const string& neighbor : adj[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    unvisited.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        if (!unvisited.empty()) {
            if (curr != start) {
                frontier.push_front(curr);
            }
            for (int i = (int)unvisited.size() - 1; i >= 0; --i) {
                frontier.push_front(unvisited[i]);
            }
        }
    }
    cout << endl;

    return 0;
}
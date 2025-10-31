/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string city;
    int heuristic;
};

struct Edge {
    string from, to;
    int cost;
};

struct State {
    vector<string> path;
    int total_cost;
};

struct Comparator {
    bool operator()(const State& a, const State& b) {
        return a.total_cost > b.total_cost;
    }
};

int main() {
    string start, goal;
    getline(cin, start);
    getline(cin, goal);

    unordered_map<string, int> heuristics;
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string city;
        int h;
        ss >> city >> h;
        heuristics[city] = h;
    }

    unordered_map<string, vector<Edge>> graph;
    while (getline(cin, line)) {
        stringstream ss(line);
        string from, to;
        int cost;
        ss >> from >> to >> cost;
        graph[from].push_back({from, to, cost});
        graph[to].push_back({to, from, cost}); // bidirectional
    }

    priority_queue<State, vector<State>, Comparator> pq;
    pq.push({{start}, heuristics[start]});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        string current_city = current.path.back();
        if (current_city == goal) {
            for (const auto& city : current.path) cout << city << " ";
            cout << endl;
            return 0;
        }

        vector<vector<string>> states;
        for (const Edge& edge : graph[current_city]) {
            vector<string> new_path = current.path;
            new_path.push_back(edge.to);
            int new_cost = current.total_cost + edge.cost + heuristics[edge.to];
            pq.push({new_path, new_cost});
            states.push_back(new_path);
        }

        for (const auto& state : states) {
            cout << "[";
            for (size_t i = 0; i < state.size(); ++i) {
                cout << "'" << state[i] << "'";
                if (i < state.size() - 1) cout << ", ";
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}

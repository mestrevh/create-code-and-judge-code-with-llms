/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    string city;
    int h;
    Node(string c, int heuristic) : city(c), h(heuristic) {}
};

struct Edge {
    string dest;
    int cost;
    Edge(string d, int c) : dest(d), cost(c) {}
};

struct State {
    string city;
    int g;
    int h;
    int f;
    vector<string> path;

    bool operator>(const State& other) const {
        return f > other.f;
    }
};

int main() {
    string start, goal;
    getline(cin, start);
    getline(cin, goal);

    unordered_map<string, int> heuristics;
    string line;
    while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        string city;
        int h;
        iss >> city >> h;
        heuristics[city] = h;
    }

    unordered_map<string, vector<Edge>> graph;
    while (getline(cin, line)) {
        istringstream iss(line);
        string city1, city2;
        int cost;
        iss >> city1 >> city2 >> cost;
        graph[city1].emplace_back(city2, cost);
        graph[city2].emplace_back(city1, cost); // bidirectional
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State{start, 0, heuristics[start], heuristics[start]});
    vector<string> visited;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.city == goal) {
            for (const auto& city : current.path) {
                cout << city << " ";
            }
            cout << goal << endl;
            break;
        }

        visited.push_back(current.city);
        current.path.push_back(current.city);
        
        cout << "[";
        cout << "[";
        for (const auto& city : current.path) {
            cout << city << " ";
        }
        cout << "], ";
        cout << heuristics[current.city] << "]" << endl;

        for (const auto& edge : graph[current.city]) {
            if (find(visited.begin(), visited.end(), edge.dest) == visited.end()) {
                pq.push(State{edge.dest, current.g + edge.cost, heuristics[edge.dest], current.g + edge.cost + heuristics[edge.dest]});
            }
        }
    }

    return 0;
}

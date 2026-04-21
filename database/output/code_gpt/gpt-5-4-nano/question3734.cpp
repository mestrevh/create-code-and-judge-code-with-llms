/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    auto readNonEmptyLine = [&]() -> bool {
        while (std::getline(cin, line)) {
            if (!line.empty() && line.find_first_not_of(" \t\r\n") != string::npos) return true;
        }
        return false;
    };

    char start = 0, goal = 0;

    if (!readNonEmptyLine()) return 0;
    start = 0;
    for (char c : line) {
        if (!isspace((unsigned char)c)) { start = c; break; }
    }
    if (!readNonEmptyLine()) return 0;
    goal = 0;
    for (char c : line) {
        if (!isspace((unsigned char)c)) { goal = c; break; }
    }

    unordered_map<char, vector<pair<char,int>>> adj;

    while (std::getline(cin, line)) {
        bool allspace = true;
        for (char c : line) if (!isspace((unsigned char)c)) { allspace = false; break; }
        if (allspace) break;

        stringstream ss(line);
        char X, Y;
        long long D;
        if (!(ss >> X >> Y >> D)) continue;
        if (D < 0) continue;
        adj[X].push_back({Y, (int)D});
    }

    struct State {
        long long cost;
        char node;
    };

    struct PQComp {
        bool operator()(const State& a, const State& b) const {
            if (a.cost != b.cost) return a.cost < b.cost; 
            return a.node > b.node;
        }
    };

    priority_queue<State, vector<State>, PQComp> pq;
    map<char, long long> best;
    map<char, bool> visited;

    pq.push({0, start});
    best[start] = 0;

    vector<char> path;
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        char u = cur.node;
        long long c = cur.cost;

        if (visited[u]) continue;
        if (!best.count(u) || c != best[u]) continue;

        vector<pair<char,long long>> snapshot;
        for (auto &it : best) {
            char n = it.first;
            if (!visited[n]) snapshot.push_back({n, it.second});
        }
        sort(snapshot.begin(), snapshot.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });

        cout << "[";
        for (size_t i = 0; i < snapshot.size(); i++) {
            if (i) cout << ", ";
            cout << "(" << snapshot[i].second << ", '" << snapshot[i].first << "')";
        }
        cout << "]\n";

        visited[u] = true;
        path.push_back(u);
        if (u == goal) break;

        auto it = adj.find(u);
        if (it == adj.end()) continue;
        for (auto &e : it->second) {
            char v = e.first;
            int w = e.second;
            if (visited[v]) continue;
            long long nc = c + w;
            if (!best.count(v) || nc < best[v]) {
                best[v] = nc;
                pq.push({nc, v});
            }
        }
    }

    cout << "[";
    for (size_t i = 0; i < path.size(); i++) {
        if (i) cout << ", ";
        cout << "'" << path[i] << "'";
    }
    cout << "]\n";

    return 0;
}
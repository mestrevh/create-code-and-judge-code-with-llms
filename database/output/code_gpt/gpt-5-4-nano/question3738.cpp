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
    vector<string> lines;
    while (true) {
        if (!std::getline(cin, line)) break;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        lines.push_back(line);
    }
    while (!lines.empty() && lines.back().empty()) lines.pop_back();
    if (lines.size() < 2) return 0;

    char start = '\0', goal = '\0';
    int idx = 0;

    while (idx < (int)lines.size() && lines[idx].empty()) idx++;
    if (idx >= (int)lines.size()) return 0;
    start = lines[idx][0];
    idx++;

    while (idx < (int)lines.size() && lines[idx].empty()) idx++;
    if (idx >= (int)lines.size()) return 0;
    goal = lines[idx][0];
    idx++;

    unordered_map<char, vector<char>> adj;
    for (int i = idx; i < (int)lines.size(); i++) {
        if (lines[i].empty()) continue;
        char X, Y;
        int D;
        if (sscanf(lines[i].c_str(), " %c->%c %d", &X, &Y, &D) == 3) {
            adj[X].push_back(Y);
        }
    }

    for (auto &p : adj) {
        auto &v = p.second;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    queue<char> q;
    unordered_set<char> vis;
    unordered_map<char, char> parent;

    vis.insert(start);
    q.push(start);

    auto printQueue = [&](queue<char> qq) {
        bool first = true;
        while (!qq.empty()) {
            char u = qq.front(); qq.pop();
            if (!first) cout << ' ';
            first = false;
            cout << u;
        }
        cout << "\n";
    };

    while (!q.empty()) {
        queue<char> qq = q;
        if (q.front() == goal) break;

        char u = q.front(); q.pop();

        for (char v : adj[u]) {
            if (!vis.count(v)) {
                vis.insert(v);
                parent[v] = u;
                q.push(v);
            }
        }

        if (!q.empty()) {
            printQueue(q);
        }
    }

    vector<char> path;
    if (vis.count(goal)) {
        char cur = goal;
        while (true) {
            path.push_back(cur);
            if (cur == start) break;
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
    }

    for (size_t i = 0; i < path.size(); i++) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << "\n";

    if (path.size() >= 2) {
        for (size_t i = 0; i < path.size(); i++) {
            if (i) cout << ' ';
        }
    }

    if (path.size() >= 1) cout.flush();

    return 0;
}
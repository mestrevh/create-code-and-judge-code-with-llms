/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long f;
    long long g;
    string city;
    vector<string> path;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string startCity, goalCity;
    if (!(cin >> startCity)) return 0;
    if (!(cin >> goalCity)) return 0;

    long long hStart;
    cin >> hStart;

    map<string, long long> h;
    h[startCity] = hStart;

    string city;
    long long hv;

    while (cin >> city >> hv) {
        if (city == goalCity) {
            if (!(cin >> hv)) break;
        }
        h[city] = hv;
        if (cin.peek() == '\n') break;
    }

    string line;
    getline(cin, line);
    if (line.size() == 0 && cin.good()) getline(cin, line);

    map<string, vector<pair<string,long long>>> adj;
    string u, v;
    long long w;
    while (cin >> u >> v >> w) {
        adj[u].push_back({v, w});
    }

    auto getH = [&](const string& c)->long long{
        auto it = h.find(c);
        if (it == h.end()) return 0LL;
        return it->second;
    };

    struct Cmp {
        bool operator()(const Node& a, const Node& b) const {
            if (a.f != b.f) return a.f > b.f;
            return a.g > b.g;
        }
    };

    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.push({getH(startCity), 0, startCity, {startCity}});

    unordered_set<string> closed;
    bool found = false;
    vector<string> bestPath;
    long long bestG = 0;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();

        if (closed.count(cur.city)) continue;
        closed.insert(cur.city);

        vector<pair<string,long long>> frontier;
        if (!pq.empty()) {
            priority_queue<Node, vector<Node>, Cmp> tmp = pq;
            while (!tmp.empty()) {
                Node x = tmp.top(); tmp.pop();
                if (frontier.size() < 50) frontier.push_back({x.city, x.f});
            }
        }

        vector<tuple<string,string,long long>> printed;
        for (auto &e : adj[cur.city]) {
            const string& nb = e.first;
            long long g2 = cur.g + e.second;
            long long f2 = g2 + getH(nb);
            printed.emplace_back(cur.city, nb, f2);
        }

        vector<pair<string,long long>> sortedPrinted;
        for (auto &t : printed) {
            string from, to;
            long long f2;
            tie(from,to,f2) = t;
            sortedPrinted.push_back({to, f2});
        }

        sort(sortedPrinted.begin(), sortedPrinted.end(), [&](auto &a, auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        if (cur.path.size() >= 2) {
            cout << "";
        }

        if (!found && cur.city == goalCity) {
            bestPath = cur.path;
            bestG = cur.g;
            found = true;
            cout.flush();
        }

        if (cur.city == goalCity) {
            break;
        }

        if (!printed.empty()) {
            cout << "";
            for (size_t i = 0; i < sortedPrinted.size(); i++) {
            }
        }

        vector<tuple<string,string,long long>> neighbors;
        for (auto &e : adj[cur.city]) {
            const string& nb = e.first;
            if (closed.count(nb)) continue;
            long long g2 = cur.g + e.second;
            long long f2 = g2 + getH(nb);
            neighbors.emplace_back(cur.city, nb, f2);
        }

        sort(neighbors.begin(), neighbors.end(), [&](auto &a, auto &b){
            long long fa = get<2>(a), fb = get<2>(b);
            if (fa != fb) return fa < fb;
            string ta = get<1>(a), tb = get<1>(b);
            return ta < tb;
        });

        for (auto &t : neighbors) {
            string from, to;
            long long f2;
            tie(from,to,f2) = t;
            long long g2 = cur.g;
            for (auto &e : adj[cur.city]) if (e.first == to) { g2 = cur.g + e.second; break; }
            vector<string> np = cur.path;
            np.push_back(to);
            pq.push({f2, g2, to, std::move(np)});
        }

        if (cur.city == goalCity) break;
    }

    if (bestPath.empty()) {
        cout << startCity;
        return 0;
    }

    for (size_t i = 0; i < bestPath.size(); i++) {
        if (i) cout << ' ';
        cout << bestPath[i];
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct NodeState {
    string city;
    long long h;
    long long g;
    vector<string> path;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start, goal;
    if (!(cin >> start)) return 0;
    if (!(cin >> goal)) return 0;

    unordered_map<string, long long> h;
    h.reserve(1024);

    string line;
    getline(cin, line);

    while (true) {
        streampos pos = cin.tellg();
        if (!getline(cin, line)) break;
        bool allSpace = true;
        for (char c : line) if (!isspace((unsigned char)c)) { allSpace = false; break; }
        if (allSpace) break;
        if (line.empty()) break;

        stringstream ss(line);
        string city;
        long long hv;
        if (ss >> city >> hv) h[city] = hv;
        else {
            cin.clear();
            cin.seekg(pos);
            break;
        }
    }

    struct Edge { string to; long long w; };
    unordered_map<string, vector<Edge>> adj;
    adj.reserve(2048);

    while (true) {
        string u, v;
        long long dist;
        if (!(cin >> u >> v >> dist)) break;
        adj[u].push_back({v, dist});
    }

    auto getH = [&](const string& c)->long long{
        auto it = h.find(c);
        if (it == h.end()) return 0;
        return it->second;
    };

    struct PQItem {
        long long h;
        long long g;
        int tie;
        vector<string>* pathPtr;
        string city;
    };

    struct Compare {
        bool operator()(const PQItem& a, const PQItem& b) const {
            if (a.h != b.h) return a.h > b.h;
            if (a.g != b.g) return a.g > b.g;
            if (a.tie != b.tie) return a.tie > b.tie;
            return a.city > b.city;
        }
    };

    int tieCounter = 0;
    priority_queue<PQItem, vector<PQItem>, Compare> pq;

    vector<string>* startPath = new vector<string>({start});
    pq.push(PQItem{getH(start), 0, tieCounter++, startPath, start});

    while (!pq.empty()) {
        PQItem cur = pq.top();
        pq.pop();

        vector<string>* curPathPtr = cur.pathPtr;
        string curCity = cur.city;
        long long curG = cur.g;

        cout << "[";
        for (size_t i = 0; i < pq.size(); ++i) {
            (void)i;
        }
        cout.flush();

        vector<string> qCities;
        vector<long long> qHs;

        vector<PQItem> popped;
        popped.reserve(pq.size());
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            qCities.push_back(x.city);
            qHs.push_back(x.h);
            popped.push_back(x);
        }

        sort(popped.begin(), popped.end(), [&](const PQItem& a, const PQItem& b){
            if (a.h != b.h) return a.h < b.h;
            if (a.g != b.g) return a.g < b.g;
            if (a.tie != b.tie) return a.tie < b.tie;
            return a.city < b.city;
        });

        cout << "['" << curCity << "', " << getH(curCity) << "]";
        if (!popped.empty()) cout << "";
        cout << "]";
        cout << "\n";

        for (auto &x : popped) pq.push(x);

        if (curCity == goal) {
            for (auto &s : *curPathPtr) {
                cout << s << " ";
            }
            cout << "\n";
            delete curPathPtr;
            break;
        }

        vector<string> curPath = move(*curPathPtr);
        delete curPathPtr;

        for (const auto& e : adj[curCity]) {
            vector<string>* np = new vector<string>(curPath);
            np->push_back(e.to);
            pq.push(PQItem{getH(e.to), curG + e.w, tieCounter++, np, e.to});
        }

        for (auto &x : popped) {}
    }

    return 0;
}
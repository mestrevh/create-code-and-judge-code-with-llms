/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (true) {
        if (!std::getline(cin, line)) break;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        lines.push_back(line);
    }
    if (lines.empty()) return 0;

    string start = lines[0];
    if (!start.empty()) {
        while (!start.empty() && isspace((unsigned char)start.back())) start.pop_back();
        while (!start.empty() && isspace((unsigned char)start.front())) start.erase(start.begin());
    }
    if (lines.size() == 1) return 0;

    string goal = lines[1];
    if (!goal.empty()) {
        while (!goal.empty() && isspace((unsigned char)goal.back())) goal.pop_back();
        while (!goal.empty() && isspace((unsigned char)goal.front())) goal.erase(goal.begin());
    }

    char startNode = start.empty() ? '\0' : start[0];
    char goalNode = goal.empty() ? '\0' : goal[0];

    unordered_map<char, vector<pair<char,int>>> adj;
    auto parseEdge = [&](const string& s) {
        size_t posArrow = s.find("->");
        if (posArrow == string::npos) return;
        if (posArrow == 0 || posArrow + 2 >= s.size()) return;
        char X = s[posArrow - 1];
        size_t i = posArrow + 2;
        char Y = s[i];
        size_t j = i + 1;
        while (j < s.size() && isspace((unsigned char)s[j])) j++;
        int D = 0;
        bool neg = false;
        if (j < s.size() && s[j] == '-') { neg = true; j++; }
        while (j < s.size() && isdigit((unsigned char)s[j])) {
            D = D * 10 + (s[j] - '0');
            j++;
        }
        if (neg) D = -D;
        adj[X].push_back({Y, D});
        adj[Y].push_back({X, D});
    };

    for (size_t idx = 2; idx < lines.size(); idx++) {
        string s = lines[idx];
        if (!s.empty() && s.back() == '\r') s.pop_back();
        bool allspace = true;
        for (char c : s) if (!isspace((unsigned char)c)) { allspace = false; break; }
        if (allspace) continue;
        parseEdge(s);
    }

    for (auto &kv : adj) {
        auto &vec = kv.second;
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) return a.second < b.second;
            if (a.first != b.first) return a.first < b.first;
            return false;
        });
    }

    vector<char> visited;
    vector<char> stackPath;
    unordered_set<char> seen;
    if (startNode != '\0') {
        stack<char> st;
        st.push(startNode);
        stackPath.push_back(startNode);
        vector<char> order;
        seen.clear();

        while (!st.empty()) {
            char u = st.top();
            if (!seen.count(u)) {
                seen.insert(u);
                order.push_back(u);
                stackPath.back() = u;
            }
            bool pushed = false;

            auto &nbrs = adj[u];
            for (auto &pr : nbrs) {
                char v = pr.first;
                if (!seen.count(v)) {
                    st.push(v);
                    stackPath.push_back(v);
                    pushed = true;
                    break;
                }
            }

            if (!pushed) {
                st.pop();
                stackPath.pop_back();
            }
        }

        for (char c : order) {
            cout << c;
            if (c != order.back()) cout << ' ';
        }
        cout << "\n";
        cout << "\n";
    }

    return 0;
}
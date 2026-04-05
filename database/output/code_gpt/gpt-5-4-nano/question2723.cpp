/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void distribute(const unordered_map<string, string>& nxt, const string& start, unordered_set<string>& visited, vector<string>& order, const string& cur) {
    if (visited.count(cur)) return;
    visited.insert(cur);
    auto it = nxt.find(cur);
    if (it == nxt.end()) return;
    order.push_back(cur);
    distribute(nxt, start, visited, order, it->second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    unordered_map<string, string> nxt;
    nxt.reserve((size_t)N * 2);

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        nxt[a] = b;
    }

    string start;
    cin >> start;

    unordered_set<string> visited;
    visited.reserve((size_t)N * 2);
    vector<string> order;
    order.reserve(N);

    distribute(nxt, start, visited, order, start);

    for (size_t i = 0; i < order.size(); i++) {
        if (i) cout << ' ';
        cout << order[i];
    }
    return 0;
}
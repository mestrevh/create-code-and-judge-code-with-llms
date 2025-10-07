/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool isCubo(int k, const vector<pair<int, int>>& edges) {
    if (k & (k - 1)) return false; 
    vector<vector<int>> graph(k);
    unordered_map<int, int> degree;

    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
        degree[edge.first]++;
        degree[edge.second]++;
    }

    for (int i = 0; i < k; ++i) {
        if (degree[i] != k / 2) return false; 
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int k, m;
        cin >> k >> m;
        if (k == 0) break;
        
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        
        cout << (isCubo(k, edges) ? "SIM" : "NAO") << '\n';
    }
    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> names;
    map<string, int> nameToId;
    vector<vector<int>> adj;

    for (int i = 0; i < N; ++i) {
        string p, f;
        cin >> p >> f;
        if (nameToId.find(p) == nameToId.end()) {
            nameToId[p] = names.size();
            names.push_back(p);
            adj.push_back({});
        }
        if (nameToId.find(f) == nameToId.end()) {
            nameToId[f] = names.size();
            names.push_back(f);
            adj.push_back({});
        }
        int u = nameToId[p];
        int v = nameToId[f];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int V = (int)names.size();
    if (V < 2) return 0;

    int maxD = -1;
    pair<int, int> bestIds = {V + 1, V + 1};

    vector<int> dist(V);
    for (int i = 0; i < V; ++i) {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u > i) {
                if (dist[u] > maxD) {
                    maxD = dist[u];
                    bestIds = {i, u};
                } else if (dist[u] == maxD) {
                    if (i < bestIds.first || (i == bestIds.first && u < bestIds.second)) {
                        bestIds = {i, u};
                    }
                }
            }

            for (int v_adj : adj[u]) {
                if (dist[v_adj] == -1) {
                    dist[v_adj] = dist[u] + 1;
                    q.push(v_adj);
                }
            }
        }
    }

    if (maxD != -1) {
        string s1 = names[bestIds.first];
        string s2 = names[bestIds.second];
        if (s1 > s2) swap(s1, s2);
        cout << s1 << " " << s2 << " " << maxD << "\n";
    }

    return 0;
}
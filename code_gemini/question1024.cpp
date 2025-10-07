/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> adj;
vector<int> disc, low;
vector<pair<int, int>> bridges;
int timer;
int n;

void find_bridges_dfs(int u, int p) {
    disc[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (disc[v] != -1) {
            low[u] = min(low[u], disc[v]);
        } else {
            find_bridges_dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n) {
        adj.assign(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int u, d;
            char dummy;
            cin >> u >> dummy >> d >> dummy;
            for (int j = 0; j < d; ++j) {
                int v;
                cin >> v;
                adj[u].push_back(v);
            }
        }

        disc.assign(n, -1);
        low.assign(n, -1);
        bridges.clear();
        timer = 0;

        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) {
                find_bridges_dfs(i, -1);
            }
        }

        sort(bridges.begin(), bridges.end());

        cout << bridges.size() << " critical links" << endl;
        for (const auto& bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << endl;
        }
        cout << endl;
    }

    return 0;
}

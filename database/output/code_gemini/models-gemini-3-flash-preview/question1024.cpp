/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> tin, low;
int timer;
vector<pair<int, int>> bridges;

void dfs(int u, int p) {
    tin[u] = low[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                int first = u;
                int second = v;
                if (first > second) swap(first, second);
                bridges.push_back({first, second});
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        adj.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int u, k;
            if (scanf(" %d (%d)", &u, &k) != 2) break;
            for (int j = 0; j < k; j++) {
                int v;
                scanf("%d", &v);
                adj[u].push_back(v);
            }
        }

        tin.assign(n, 0);
        low.assign(n, 0);
        timer = 0;
        bridges.clear();

        for (int i = 0; i < n; i++) {
            if (!tin[i]) {
                dfs(i, -1);
            }
        }

        sort(bridges.begin(), bridges.end());

        printf("%d critical links\n", (int)bridges.size());
        for (const auto& b : bridges) {
            printf("%d - %d\n", b.first, b.second);
        }
        printf("\n");
    }
    return 0;
}
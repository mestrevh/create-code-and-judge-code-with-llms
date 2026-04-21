/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int id;
};

vector<Edge> adj[30];
bool used[30];
int res;

void solve(int u, int dist) {
    if (dist > res) {
        res = dist;
    }
    for (const auto& e : adj[u]) {
        if (!used[e.id]) {
            used[e.id] = true;
            solve(e.to, dist + 1);
            used[e.id] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        for (int i = 0; i < 30; ++i) {
            adj[i].clear();
            used[i] = false;
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (u < 30 && v < 30) {
                adj[u].push_back({v, i});
                adj[v].push_back({u, i});
            }
        }

        res = 0;
        for (int i = 0; i < n; ++i) {
            solve(i, 0);
        }
        cout << res << "\n";
    }

    return 0;
}
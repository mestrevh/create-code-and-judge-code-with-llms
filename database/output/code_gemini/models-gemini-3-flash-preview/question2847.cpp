/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, t;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].t;
    }

    vector<int> dist(n, 0);
    bool possible = false;

    for (int i = 0; i < n; ++i) {
        bool changed = false;
        for (int j = 0; j < m; ++j) {
            if (dist[edges[j].u] + edges[j].t < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].t;
                changed = true;
                if (i == n - 1) {
                    possible = true;
                }
            }
        }
        if (!changed) break;
    }

    if (possible) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >> c)) return 0;
    while (c--) {
        solve();
    }
    return 0;
}
/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

vector<int> adj[MAXN];
int disc[MAXN], low[MAXN];
int timer;
bool hasBridge;

void findBridges(int u, int p) {
    if (hasBridge) return;

    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (disc[v] != -1) {
            low[u] = min(low[u], disc[v]);
        } else {
            findBridges(v, u);
            if (hasBridge) return;
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                hasBridge = true;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
            disc[i] = -1;
            low[i] = -1;
        }

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        hasBridge = false;
        
        findBridges(1, -1);

        if (hasBridge) {
            cout << "N\n";
        } else {
            cout << "S\n";
        }
    }

    return 0;
}

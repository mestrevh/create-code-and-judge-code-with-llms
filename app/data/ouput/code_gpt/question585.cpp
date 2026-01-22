/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Tunnel {
    int to, length;
    Tunnel(int t, int l) : to(t), length(l) {}
};

vector<vector<Tunnel>> graph;
vector<int> cycle_lengths;
vector<bool> visited;
int S, T;

void dfs(int node, int parent, int length) {
    visited[node] = true;
    for (const auto& tunnel : graph[node]) {
        if (!visited[tunnel.to]) {
            dfs(tunnel.to, node, length + tunnel.length);
        } else if (tunnel.to != parent) {
            cycle_lengths.push_back(length + tunnel.length);
        }
    }
}

int main() {
    cin >> S >> T;
    graph.resize(S + 1);
    for (int i = 0; i < T; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].emplace_back(B, C);
        graph[B].emplace_back(A, C);
    }

    visited.assign(S + 1, false);
    for (int i = 1; i <= S; ++i) {
        if (!visited[i]) {
            dfs(i, -1, 0);
        }
    }

    cycle_lengths.assign(S + 1, INT_MAX);
    for (int i = 1; i <= S; ++i) {
        for (const auto& tunnel : graph[i]) {
            if (cycle_lengths[i] > tunnel.length) {
                cycle_lengths[i] = tunnel.length;
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int X, M;
        cin >> X >> M;
        if (cycle_lengths[X] <= M) {
            cout << 2 * cycle_lengths[X] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}

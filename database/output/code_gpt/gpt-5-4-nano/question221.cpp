/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long D;
    if (!(cin >> N >> D)) return 0;

    vector<long long> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    long long D2 = D * D;

    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            if (dx * dx + dy * dy <= D2) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<char> vis(N, 0);
    queue<int> q;
    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            cout << 'N' << "\n";
            return 0;
        }
    }

    cout << 'S' << "\n";
    return 0;
}
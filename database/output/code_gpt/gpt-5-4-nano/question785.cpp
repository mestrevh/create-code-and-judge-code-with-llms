/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;
    for (int tc = 0; tc < C; tc++) {
        int N, S;
        cin >> N;
        cin >> S;

        vector<vector<int>> adj(N);
        adj.reserve(N);

        for (int j = 0; j < N; j++) {
            int K;
            cin >> K;
            adj[j].resize(K);
            for (int i = 0; i < K; i++) cin >> adj[j][i];
        }

        vector<int> dist(N, -1);
        queue<int> q;
        dist[S] = 0;
        q.push(S);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int maxd = 0;
        for (int i = 0; i < N; i++) {
            if (dist[i] > maxd) maxd = dist[i];
        }

        vector<int> t(maxd + 1, 0);
        for (int i = 0; i < N; i++) {
            if (dist[i] >= 0) t[dist[i]]++;
        }
        for (int s = 1; s <= maxd; s++) t[s] += t[s - 1];

        cout << "caso " << tc << ":";
        for (int s = 0; s <= maxd; s++) cout << " " << t[s];
        cout << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, teste = 1;
    while (cin >> N && N != 0) {
        vector<int> deg(7, 0);
        vector<vector<int>> adj(7);
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            deg[x]++;
            deg[y]++;
            if (x == y) {
                adj[x].push_back(y);
            } else {
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }

        int start = -1;
        for (int i = 0; i <= 6; ++i) {
            if (deg[i] > 0) {
                start = i;
                break;
            }
        }

        bool connected = true;
        if (start != -1) {
            vector<int> vis(7, 0);
            queue<int> q;
            q.push(start);
            vis[start] = 1;
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
            for (int i = 0; i <= 6; ++i) {
                if (deg[i] > 0 && !vis[i]) {
                    connected = false;
                    break;
                }
            }
        }

        int odd = 0;
        for (int i = 0; i <= 6; ++i) {
            if (deg[i] % 2) odd++;
        }

        bool ok = connected && (odd == 0 || odd == 2);

        cout << "Teste " << teste++ << "\n";
        cout << (ok ? "sim" : "nao") << "\n\n";
    }

    return 0;
}
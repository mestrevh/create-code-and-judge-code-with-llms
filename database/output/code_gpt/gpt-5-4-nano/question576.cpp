/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        int e;
        cin >> e;

        vector<vector<int>> adj(n);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            if (a >= 0 && a < n && b >= 0 && b < n && a != b) {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }

        vector<int> color(n, -1);
        bool ok = true;

        for (int start = 0; start < n && ok; start++) {
            if (color[start] != -1) continue;
            queue<int> q;
            color[start] = 0;
            q.push(start);

            while (!q.empty() && ok) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
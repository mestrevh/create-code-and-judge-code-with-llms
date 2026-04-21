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
    int tc = 1;
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<int> deg(7, 0);
        vector<vector<pair<int,int>>> adj(7);
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            a[i] = X; b[i] = Y;
            adj[X].push_back({Y, i});
            adj[Y].push_back({X, i});
            deg[X]++; deg[Y]++;
        }

        int start = -1;
        for (int i = 0; i < 7; i++) if (deg[i] > 0) { start = i; break; }

        bool possible = true;

        if (start == -1) {
            possible = true;
        } else {
            int odd = 0;
            for (int i = 0; i < 7; i++) if (deg[i] % 2 == 1) odd++;
            if (odd != 0 && odd != 2) possible = false;

            vector<int> visV(7, 0);
            queue<int> q;
            q.push(start);
            visV[start] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto &e : adj[u]) {
                    int v = e.first;
                    if (!visV[v]) {
                        visV[v] = 1;
                        q.push(v);
                    }
                }
            }
            for (int i = 0; i < 7; i++) {
                if (deg[i] > 0 && !visV[i]) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Teste " << tc++ << "\n";
        cout << (possible ? "sim" : "nao") << "\n\n";
    }
    return 0;
}
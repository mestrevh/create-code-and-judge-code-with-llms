/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, N;
    if (!(cin >> X >> Y >> N)) return 0;

    vector<int> parent(N + 1);
    vector<vector<int>> children(N + 1);
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p >= 0 && p <= N) children[p].push_back(i);
    }

    queue<int> q;
    vector<int> depth(N + 1, -1);
    depth[0] = 0;
    for (int v : children[0]) {
        depth[v] = 1;
        q.push(v);
    }

    int countSub = 0;
    for (int v = 1; v <= N; v++) if (depth[v] != -1) {}

    int days = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        int d = depth[v];
        if (d <= Y) countSub++;
        if (d < Y) {
            for (int u : children[v]) {
                depth[u] = d + 1;
                q.push(u);
            }
        }
    }

    cout << (countSub >= X ? "S" : "N");
    return 0;
}
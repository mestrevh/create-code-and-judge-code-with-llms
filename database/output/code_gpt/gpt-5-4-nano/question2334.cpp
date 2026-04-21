/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> name(N);
    unordered_map<string,int> id;
    id.reserve(N * 2);

    for (int i = 0; i < N; i++) {
        cin >> name[i];
        id[name[i]] = i;
    }

    vector<vector<int>> adj(N);
    for (int k = 0; k < M; k++) {
        int I, J;
        cin >> I >> J;
        if (0 <= I && I < N && 0 <= J && J < N) adj[I].push_back(J);
    }

    string A, B;
    cin >> A >> B;
    int s = id[A], t = id[B];

    vector<int> vis(N, 0);
    function<bool(int)> dfs = [&](int u) -> bool {
        if (u == t) return true;
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v] && dfs(v)) return true;
        }
        return false;
    };

    bool ok = dfs(s);
    if (ok) cout << "We're all in this together!";
    else cout << "Mentira, nenhum filme da Disney da errado, nunca.";

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while ( (cin >> n >> m) ) {
        if (n == 0 && m == 0) break;

        vector<pair<int,int>> edges(m);
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        int best = 0;
        int E = m;
        vector<int> edgeToV(m);
        vector<int> otherV(m);
        vector<array<int,2>> endpoints(m);

        for (int i = 0; i < m; i++) {
            endpoints[i] = {edges[i].first, edges[i].second};
        }

        int maxMask = (E == 0 ? 1 : (1 << E));
        if (E > 25) {
            return 0;
        }

        vector<int> memo(maxMask, -1);
        deque<int> dq;

        function<int(int,int)> dfs = [&](int usedMask, int lastV) -> int {
            int &res = memo[usedMask];
            if (res != -1) return res;
            res = 0;

            for (auto [to, eid] : adj[lastV]) {
                if (usedMask & (1 << eid)) continue;
                int nmask = usedMask | (1 << eid);
                res = max(res, 1 + dfs(nmask, to));
            }
            return res;
        };

        if (E == 0) {
            cout << 0 << "\n";
            continue;
        }

        for (int start = 0; start < n; start++) {
            int usedMask = 0;
            vector<int> memo2(maxMask, -1);
            function<int(int,int)> dfs2 = [&](int usedMask2, int lastV) -> int {
                int &r = memo2[usedMask2];
                if (r != -1) return r;
                r = 0;
                for (auto [to, eid] : adj[lastV]) {
                    if (usedMask2 & (1 << eid)) continue;
                    r = max(r, 1 + dfs2(usedMask2 | (1 << eid), to));
                }
                return r;
            };
            best = max(best, dfs2(0, start));
        }

        cout << best << "\n";
    }
    return 0;
}
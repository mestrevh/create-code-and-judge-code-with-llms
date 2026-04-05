/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B, N;
    while ( (cin >> B >> N) ) {
        if (B == 0 && N == 0) break;

        vector<long long> R(B+1);
        for (int i = 1; i <= B; i++) cin >> R[i];

        vector<vector<pair<int,int>>> adj(B+1), radj(B+1);
        vector<long long> V;
        V.reserve(N);
        for (int i = 0; i < N; i++) {
            int D, C, val;
            cin >> D >> C >> val;
            int idx = i;
            adj[D].push_back({C, idx});
            radj[C].push_back({D, idx});
            V.push_back(val);
        }

        vector<int> order;
        vector<char> vis(B+1, 0);
        order.reserve(B);

        for (int s = 1; s <= B; s++) {
            if (vis[s]) continue;
            vector<pair<int,int>> st;
            st.push_back({s, 0});
            vis[s] = 1;
            while (!st.empty()) {
                int u = st.back().first;
                int &it = st.back().second;
                if (it < (int)adj[u].size()) {
                    int v = adj[u][it].first;
                    it++;
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push_back({v, 0});
                    }
                } else {
                    order.push_back(u);
                    st.pop_back();
                }
            }
        }

        vector<int> comp(B+1, -1);
        int comps = 0;
        for (int i = (int)order.size()-1; i >= 0; i--) {
            int s = order[i];
            if (comp[s] != -1) continue;
            queue<int> q;
            q.push(s);
            comp[s] = comps;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto [v, idx] : radj[u]) {
                    (void)idx;
                    if (comp[v] == -1) {
                        comp[v] = comps;
                        q.push(v);
                    }
                }
            }
            comps++;
        }

        vector<vector<pair<int,int>>> cadj(comps);
        vector<vector<int>> cinv(comps);
        for (int u = 1; u <= B; u++) {
            int cu = comp[u];
            for (auto [v, idx] : adj[u]) {
                int cv = comp[v];
                if (cu != cv) {
                    cadj[cu].push_back({cv, idx});
                }
            }
        }

        vector<long long> reserve(comps, 0);
        for (int i = 1; i <= B; i++) reserve[comp[i]] += R[i];

        vector<long long> need(comps, 0);
        for (int u = 1; u <= B; u++) {
            int cu = comp[u];
            for (auto [v, idx] : adj[u]) {
                int cv = comp[v];
                if (cu != cv) need[cu] += V[idx];
            }
        }

        vector<vector<int>> dag(comps);
        vector<int> indeg(comps, 0);
        {
            vector<unordered_set<int>> has(comps);
            for (int u = 0; u < comps; u++) has[u].reserve(cadj[u].size()*2 + 1);
            for (int u = 0; u < comps; u++) {
                for (auto [v, idx] : cadj[u]) {
                    (void)idx;
                    if (has[u].insert(v).second) {
                        dag[u].push_back(v);
                    }
                }
            }
            for (int u = 0; u < comps; u++) {
                for (int v : dag[u]) indeg[v]++;
            }
        }

        queue<int> q;
        vector<long long> minNeed(comps, 0);
        vector<char> will(comps, 0);

        for (int i = 0; i < comps; i++) {
            minNeed[i] = need[i];
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        topo.reserve(comps);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : dag[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        vector<long long> avail(comps, 0);
        for (int i = 0; i < comps; i++) avail[i] = reserve[i];

        for (int u : topo) {
            if (!will[u]) {
                if (avail[u] < minNeed[u]) {
                    will[u] = 0;
                } else {
                    will[u] = 1;
                    avail[u] -= minNeed[u];
                }
            }
            for (int v : dag[u]) {
                minNeed[v] = max(minNeed[v], need[v]);
                avail[v] += will[u] ? avail[u] : 0;
            }
        }

        bool ok = true;
        for (int i = 0; i < comps; i++) {
            if (avail[i] + (will[i] ? 0 : 0) < need[i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? 'S' : 'N') << "\n";
    }
    return 0;
}
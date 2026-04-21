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
    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];

    unordered_map<char, int> val{
        {'b', 5},
        {'p', 10},
        {'o', 50},
        {'d', 100}
    };

    if (N <= 0 || M <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> id(N, vector<int>(M, -1));
    vector<pair<int,int>> cells;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (g[i][j] != '#') {
                id[i][j] = (int)cells.size();
                cells.push_back({i,j});
            }
        }
    }

    int S = id[0][0];
    if (S < 0) {
        cout << 0 << "\n";
        return 0;
    }

    int V = (int)cells.size();
    vector<vector<int>> adj(V);
    for (int v = 0; v < V; v++) {
        auto [x,y] = cells[v];
        static int dx[4] = {1,-1,0,0};
        static int dy[4] = {0,0,1,-1};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int u = id[nx][ny];
            if (u >= 0) adj[v].push_back(u);
        }
    }

    vector<int> w(V, 0);
    for (int v = 0; v < V; v++) {
        auto [x,y] = cells[v];
        auto it = val.find(g[x][y]);
        if (it != val.end()) w[v] = it->second;
    }

    vector<char> vis(V, 0);
    vector<int> tin(V, -1), low(V, -1);
    int timer = 0;
    vector<int> st;
    vector<vector<int>> bcc;
    vector<pair<int,int>> stEdges;

    function<void(int,int)> tarjan = [&](int u, int parentEdgeIdx) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (!vis[v]) {
                stEdges.push_back({u, v});
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    vector<int> comp;
                    while (true) {
                        auto e = stEdges.back();
                        stEdges.pop_back();
                        int a = e.first, b = e.second;
                        comp.push_back(a);
                        comp.push_back(b);
                        if ((a == u && b == v) || (a == v && b == u)) break;
                    }
                    sort(comp.begin(), comp.end());
                    comp.erase(unique(comp.begin(), comp.end()), comp.end());
                    bcc.push_back(comp);
                }
            } else if (v != parentEdgeIdx && tin[v] < tin[u]) {
                stEdges.push_back({u, v});
                low[u] = min(low[u], tin[v]);
            }
        }
    };

    tarjan(S, -1);

    int B = (int)bcc.size();
    vector<long long> bccWeight(B, 0);
    vector<int> bccOf(V, -1);

    for (int i = 0; i < B; i++) {
        long long sum = 0;
        for (int v : bcc[i]) sum += w[v];
        bccWeight[i] = sum;
    }

    vector<vector<int>> compAdj(B);
    vector<vector<int>> vertexInBcc(V);
    for (int bi = 0; bi < B; bi++) {
        for (int v : bcc[bi]) vertexInBcc[v].push_back(bi);
    }

    for (int v = 0; v < V; v++) {
        auto &lst = vertexInBcc[v];
        if (lst.size() <= 1) continue;
        for (size_t i = 0; i < lst.size(); i++) {
            for (size_t j = i+1; j < lst.size(); j++) {
                compAdj[lst[i]].push_back(lst[j]);
                compAdj[lst[j]].push_back(lst[i]);
            }
        }
    }
    for (int i = 0; i < B; i++) {
        sort(compAdj[i].begin(), compAdj[i].end());
        compAdj[i].erase(unique(compAdj[i].begin(), compAdj[i].end()), compAdj[i].end());
    }

    int srcComp = -1;
    if (!vertexInBcc[S].empty()) {
        srcComp = vertexInBcc[S][0];
    } else {
        cout << w[S] << "\n";
        return 0;
    }

    vector<char> seenB(B, 0);
    long long ans = 0;

    function<void(int,int,long long)> dfsB = [&](int u, int p, long long cur) {
        seenB[u] = 1;
        cur += bccWeight[u];
        bool progressed = false;
        for (int v : compAdj[u]) {
            if (v == p) continue;
            progressed = true;
            dfsB(v, u, cur);
        }
        if (!progressed) ans = max(ans, cur);
        seenB[u] = 0;
    };

    dfsB(srcComp, -1, 0);

    cout << ans << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<vector<int>> g(N), rg(N);
    vector<pair<int,int>> edges;
    edges.reserve(E);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
        edges.push_back({u, v});
    }

    int start, target;
    cin >> start >> target;

    vector<int> order;
    order.reserve(N);
    vector<char> vis(N, 0);

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vector<pair<int,int>> st;
        st.push_back({i, 0});
        vis[i] = 1;
        while (!st.empty()) {
            int u = st.back().first;
            int &it = st.back().second;
            if (it < (int)g[u].size()) {
                int v = g[u][it++];
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

    vector<int> comp(N, -1);
    int cid = 0;
    vector<int> stackv;
    stackv.reserve(N);

    for (int idx = N - 1; idx >= 0; idx--) {
        int v = order[idx];
        if (comp[v] != -1) continue;
        comp[v] = cid;
        stackv.clear();
        stackv.push_back(v);
        for (size_t p = 0; p < stackv.size(); p++) {
            int x = stackv[p];
            for (int y : rg[x]) {
                if (comp[y] == -1) {
                    comp[y] = cid;
                    stackv.push_back(y);
                }
            }
        }
        cid++;
    }

    int C = cid;
    vector<vector<int>> cg(C), rcg(C);
    vector<pair<int,int>> edgeListComp;
    edgeListComp.reserve(E);

    for (auto &e : edges) {
        int u = e.first, v = e.second;
        int cu = comp[u], cv = comp[v];
        edgeListComp.push_back({cu, cv});
        if (cu != cv) {
            cg[cu].push_back(cv);
            rcg[cv].push_back(cu);
        }
    }

    for (int i = 0; i < C; i++) {
        auto &a = cg[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        auto &b = rcg[i];
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
    }

    int cs = comp[start], ct = comp[target];

    vector<char> canReachTargetComp(C, 0);
    {
        deque<int> dq;
        dq.push_back(ct);
        canReachTargetComp[ct] = 1;
        while (!dq.empty()) {
            int x = dq.front();
            dq.pop_front();
            for (int y : rcg[x]) {
                if (!canReachTargetComp[y]) {
                    canReachTargetComp[y] = 1;
                    dq.push_back(y);
                }
            }
        }
    }

    vector<char> canFromStartComp(C, 0);
    {
        deque<int> dq;
        dq.push_back(cs);
        canFromStartComp[cs] = 1;
        while (!dq.empty()) {
            int x = dq.front();
            dq.pop_front();
            for (int y : cg[x]) {
                if (!canFromStartComp[y]) {
                    canFromStartComp[y] = 1;
                    dq.push_back(y);
                }
            }
        }
    }

    vector<char> inSetNode(N, 0);
    for (int i = 0; i < N; i++) {
        int c = comp[i];
        if (canFromStartComp[c] && canReachTargetComp[c]) inSetNode[i] = 1;
    }

    vector<pair<int,int>> inSetEdges;
    inSetEdges.reserve(E);
    for (int i = 0; i < E; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (inSetNode[u] && inSetNode[v]) inSetEdges.push_back({u, v});
    }

    vector<int> nodes;
    nodes.reserve(N);
    for (int i = 0; i < N; i++) if (inSetNode[i]) nodes.push_back(i);

    sort(nodes.begin(), nodes.end());

    sort(inSetEdges.begin(), inSetEdges.end());
    inSetEdges.erase(unique(inSetEdges.begin(), inSetEdges.end()), inSetEdges.end());

    cout << "Nodes set:\n";
    for (int x : nodes) cout << x << "\n";

    cout << "Edges set:\n";
    for (auto &e : inSetEdges) {
        cout << "(" << e.first << ", " << e.second << ")\n";
    }

    return 0;
}
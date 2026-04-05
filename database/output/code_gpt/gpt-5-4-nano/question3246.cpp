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

    vector<vector<pair<int,int>>> adj(N);
    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        U[i] = u; V[i] = v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    if (M == 0) {
        int start = 0;
        cout << "Yes\n" << start;
        return 0;
    }

    int odd = 0;
    vector<int> oddNodes;
    for (int i = 0; i < N; i++) {
        int deg = (int)adj[i].size();
        if (deg % 2) {
            odd++;
            oddNodes.push_back(i);
        }
    }
    if (!(odd == 0 || odd == 2)) {
        cout << "No";
        return 0;
    }

    vector<int> usedEdge(M, 0);
    vector<int> startCandidates;
    if (odd == 2) {
        startCandidates = oddNodes;
    } else {
        for (int i = 0; i < N; i++) if (!adj[i].empty()) startCandidates.push_back(i);
        if (startCandidates.empty()) {
            cout << "Yes\n0";
            return 0;
        }
    }
    sort(startCandidates.begin(), startCandidates.end());

    vector<int> path;
    bool found = false;

    auto buildWithStart = [&](int start) -> bool {
        for (int i = 0; i < M; i++) usedEdge[i] = 0;
        path.clear();
        vector<int> it(N, 0);
        vector<int> st;
        vector<int> stEdge;
        st.reserve(M + 1);
        stEdge.reserve(M + 1);

        st.push_back(start);
        stEdge.push_back(-1);

        while (!st.empty()) {
            int v = st.back();
            while (it[v] < (int)adj[v].size() && usedEdge[adj[v][it[v]].second]) it[v]++;
            if (it[v] == (int)adj[v].size()) {
                int lastEdge = stEdge.back();
                st.pop_back();
                stEdge.pop_back();
                path.push_back(v);
            } else {
                auto [to, eid] = adj[v][it[v]];
                usedEdge[eid] = 1;
                st.push_back(to);
                stEdge.push_back(eid);
            }
        }

        if ((int)path.size() != M + 1) return false;
        reverse(path.begin(), path.end());
        return true;
    };

    for (int s : startCandidates) {
        vector<int> deg = vector<int>(N, 0);
        for (int i = 0; i < N; i++) deg[i] = adj[i].size();
        if (!buildWithStart(s)) continue;

        int maxIdx = N - 1;
        bool ok = true;
        for (int v = 0; v < N && ok; v++) {
            if (deg[v] == 0) continue;
        }
        found = true;
        break;
    }

    if (!found) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    for (int i = 0; i < (int)path.size(); i++) {
        if (i) cout << ' ';
        cout << path[i];
    }
    return 0;
}
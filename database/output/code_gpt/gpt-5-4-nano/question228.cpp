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
    if (!(cin >> n)) return 0;

    vector<int> pos(n, 0), parent(n, -1), sz(n, 1);
    for (int i = 0; i < n; i++) pos[i] = i;

    function<int(int)> findTop = [&](int x) {
        while (parent[x] != -1) x = parent[x];
        return x;
    };

    function<int(int)> findRoot = [&](int x) {
        while (parent[x] != -1) x = parent[x];
        return x;
    };

    auto isLegal = [&](int a, int b) -> bool {
        if (a == b) return false;
        int ra = findRoot(a);
        int rb = findRoot(b);
        return ra != rb;
    };

    auto rebuildSizesUp = [&]() {
        for (int i = 0; i < n; i++) {
            sz[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            int p = parent[i];
            if (p != -1) sz[p] = 0;
        }
        vector<int> order;
        order.reserve(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) order.push_back(i);
        }
        queue<int> q;
        for (int rt : order) q.push(rt);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int cnt = 0;
            vector<int> children;
            for (int v = 0; v < n; v++) {
                if (parent[v] == u) children.push_back(v);
            }
            sz[u] = 1;
            for (int v : children) {
                q.push(v);
                sz[u] += sz[v];
            }
        }
    };

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) g[i] = {i};

    string cmd;
    while (cin >> cmd) {
        if (cmd == "final") break;

        if (cmd == "mover") {
            int a, b;
            string type, dummy;
            cin >> a >> type >> b; 
            if (type == "sobre") {
                if (!isLegal(a, b)) continue;

                int ra = findRoot(a), rb = findRoot(b);

                vector<int> A = g[ra];
                vector<int> B = g[rb];

                int idxA = -1;
                for (int i = 0; i < (int)A.size(); i++) if (A[i] == a) { idxA = i; break; }
                vector<int> aboveA;
                vector<int> belowA;
                for (int i = 0; i < (int)A.size(); i++) {
                    if (i < idxA) belowA.push_back(A[i]);
                    else if (i > idxA) aboveA.push_back(A[i]);
                }

                int idxB = -1;
                for (int i = 0; i < (int)B.size(); i++) if (B[i] == b) { idxB = i; break; }

                vector<int> aboveB;
                for (int i = idxB + 1; i < (int)B.size(); i++) aboveB.push_back(B[i]);

                for (int x : aboveA) {
                    int rootx = x;
                    g[rootx].clear();
                    g[rootx].push_back(x);
                    parent[x] = -1;
                }
                for (int x : belowA) {
                    int rootx = ra;
                }

                if ((int)aboveA.size() > 0) {
                    g[ra].clear();
                    for (int i = 0; i < idxA; i++) g[ra].push_back(A[i]);
                    for (int i = idxA; i < (int)A.size(); i++) {
                        if (A[i] == a) break;
                    }
                    g[ra].push_back(a);
                }

                if (!g[ra].empty() && g[ra][0] != A[0]) {
                    g[ra] = belowA;
                    g[ra].push_back(a);
                } else if ((int)aboveA.size() > 0) {
                    g[ra].assign(belowA.begin(), belowA.end());
                    g[ra].push_back(a);
                } else {
                    g[ra].assign(A.begin(), A.end());
                }

                vector<int> newB;
                g[rb].clear();
                for (int x : B) {
                    if (x == b) newB.push_back(b);
                    else if (find(aboveB.begin(), aboveB.end(), x) == aboveB.end()) newB.push_back(x);
                }
                for (int x : aboveB) {
                    g[x].clear();
                    g[x].push_back(x);
                    parent[x] = -1;
                }
                g[rb].assign( g[rb].empty() ? B : B.begin(), B.end() );

                g[rb].clear();
                for (int i = 0; i <= idxB; i++) g[rb].push_back(B[i]);

                for (int x : g[ra]) parent[x] = (x == ra ? -1 : -2);
                for (int x : g[rb]) parent[x] = (x == rb ? -1 : -2);

                g[a].clear();
                g[a].push_back(a);
                parent[a] = -1;

                int rootB = rb;

                g[rootB].push_back(a);
                parent[a] = rootB;

                g[ra].clear();
                for (int x : g[rootB]) {
                    if (x == rootB) continue;
                }
                if (ra != a) {
                    g[ra].clear();
                    vector<int> remain;
                    for (int x : A) {
                        if (x == a) continue;
                        if (find(aboveA.begin(), aboveA.end(), x) != aboveA.end()) continue;
                        remain.push_back(x);
                    }
                    if (remain.empty()) g[ra].clear();
                    else {
                        g[ra] = remain;
                    }
                } else {
                    g[ra].clear();
                }

                vector<int> finalRootA = ra;
                if (g[finalRootA].empty()) g[finalRootA].assign({a});
            } else if (type == "acima") {
                if (!isLegal(a, b)) continue;

                int ra = findRoot(a), rb = findRoot(b);
                vector<int> A = g[ra];
                vector<int> B = g[rb];

                int idxA = -1;
                for (int i = 0; i < (int)A.size(); i++) if (A[i] == a) { idxA = i; break; }

                vector<int> aboveA;
                for (int i = idxA + 1; i < (int)A.size(); i++) aboveA.push_back(A[i]);

                for (int x : aboveA) {
                    g[x].clear();
                    g[x].push_back(x);
                    parent[x] = -1;
                }

                vector<int> newA;
                for (int i = 0; i <= idxA; i++) newA.push_back(A[i]);
                g[ra] = newA;

                g[a].clear();
                g[a].push_back(a);
                parent[a] = -1;

                int idxB = -1;
                for (int i = 0; i < (int)B.size(); i++) if (B[i] == b) { idxB = i; break; }

                vector<int> restB;
                g[rb].clear();
                for (int i = 0; i < (int)B.size(); i++) {
                    if (i <= idxB) restB.push_back(B[i]);
                }
                g[rb] = restB;

                g[rb].push_back(a);
                parent[a] = rb;
            }
        } else if (cmd == "pilha") {
            int a, b;
            string type;
            cin >> a >> type >> b;

            if (!isLegal(a, b)) continue;

            int ra = findRoot(a), rb = findRoot(b);
            vector<int> A = g[ra];
            vector<int> B = g[rb];

            int idxA = -1;
            for (int i = 0; i < (int)A.size(); i++) if (A[i] == a) { idxA = i; break; }

            vector<int> stackA;
            for (int i = idxA; i < (int)A.size(); i++) stackA.push_back(A[i]);

            if (type == "sobre") {
                int idxB = -1;
                for (int i = 0; i < (int)B.size(); i++) if (B[i] == b) { idxB = i; break; }

                vector<int> aboveB;
                for (int i = idxB + 1; i < (int)B.size(); i++) aboveB.push_back(B[i]);

                for (int x : aboveB) {
                    g[x].clear();
                    g[x].push_back(x);
                    parent[x] = -1;
                }

                vector<int> newB;
                for (int i = 0; i <= idxB; i++) newB.push_back(B[i]);
                g[rb] = newB;

                vector<int> remainingA;
                for (int i = 0; i < idxA; i++) remainingA.push_back(A[i]);
                if (!remainingA.empty()) g[ra] = remainingA;
                else g[ra].clear();

                for (int x : stackA) {
                    parent[x] = rb;
                }
                for (int x : stackA) {
                    g[rb].push_back(x);
                }
            } else if (type == "acima") {
                vector<int> stackAll = g[ra];
                g[ra].clear();
                for (int x : stackAll) parent[x] = rb;
                for (int x : stackAll) g[rb].insert(g[rb].end(), stackAll.begin(), stackAll.end());
            }
        }
    }

    vector<vector<int>> finalStacks(n);
    vector<int> roots;
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) if (parent[i] == -1) roots.push_back(i);

    bool any = false;
    for (int i = 0; i < n; i++) {
        if (!g[i].empty()) {
            any = true;
            break;
        }
    }
    if (!any) {
        for (int i = 0; i < n; i++) {
            cout << i << ": " << (i==0? "0":"") ;
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
            for (int j = 0; j < n; j++) {
                if (!g[j].empty()) {
                    break;
                }
            }
        }
    }

    vector<int> outputStackId(n, -1);
    for (int i = 0; i < n; i++) {
        if (!g[i].empty()) outputStackId[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        if (!g[i].empty()) {
            for (int x : g[i]) cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}
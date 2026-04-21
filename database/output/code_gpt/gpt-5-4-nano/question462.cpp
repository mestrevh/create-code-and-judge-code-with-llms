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
    while ( (cin >> N) ) {
        if (N == 0) break;

        vector<vector<int>> g(N + 1);
        string line;
        getline(cin, line);

        for (;;) {
            int S;
            if (!(cin >> S)) return 0;
            if (S == 0) break;

            int x;
            while (cin.peek() != '\n' && cin.peek() != '\r' && cin.peek() != EOF) {
                if (!(cin >> x)) break;
                if (1 <= S && S <= N && 1 <= x && x <= N) {
                    g[S].push_back(x);
                    g[x].push_back(S);
                }
            }
            getline(cin, line);
        }

        vector<int> disc(N + 1, 0), low(N + 1, 0), parent(N + 1, -1);
        vector<char> isArt(N + 1, 0);
        int timer = 0;

        for (int i = 1; i <= N; i++) {
            if (disc[i]) continue;

            stack<pair<int,int>> st;
            parent[i] = -1;
            disc[i] = low[i] = ++timer;
            int root = i;
            int rootChildren = 0;

            st.push({i, 0});
            while (!st.empty()) {
                int v = st.top().first;
                int &idx = st.top().second;

                if (idx < (int)g[v].size()) {
                    int to = g[v][idx++];
                    if (to == parent[v]) continue;
                    if (!disc[to]) {
                        parent[to] = v;
                        if (v == root) rootChildren++;
                        disc[to] = low[to] = ++timer;
                        st.push({to, 0});
                    } else {
                        low[v] = min(low[v], disc[to]);
                    }
                } else {
                    st.pop();
                    int p = parent[v];
                    if (p != -1) {
                        low[p] = min(low[p], low[v]);
                        if (low[v] >= disc[p]) isArt[p] = 1;
                    }
                }
            }
            if (rootChildren < 2) isArt[root] = 0;
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) if (isArt[i]) ans++;
        cout << ans << "\n";
    }

    return 0;
}
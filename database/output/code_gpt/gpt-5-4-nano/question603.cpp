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
        vector<string> names(N);
        unordered_map<string,int> id;
        id.reserve(N*2);

        for (int i = 0; i < N; i++) {
            cin >> names[i];
            id[names[i]] = i;
        }

        vector<vector<int>> adj(N);
        vector<int> indeg(N, 0);

        for (int i = 0; i < N; i++) {
            string a;
            int M;
            cin >> a >> M;
            int u = id[a];
            for (int j = 0; j < M; j++) {
                string b;
                cin >> b;
                int v = id[b];
                adj[v].push_back(u);
                indeg[u]++;
            }
        }

        for (int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());

        vector<int> order;
        order.reserve(N);
        deque<int> q;
        for (int i = 0; i < N; i++) if (indeg[i] == 0) q.push_back(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            order.push_back(u);
            for (int v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push_back(v);
            }
        }

        cout << "Teste " << tc++ << "\n";
        if ((int)order.size() != N) {
            cout << "impossivel\n\n";
        } else {
            for (int i = 0; i < N; i++) {
                cout << names[order[i]] << (i + 1 == N ? '\n' : ' ');
            }
            cout << "\n";
        }
    }
    return 0;
}
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
    if (!(cin >> N)) return 0;

    vector<int> head(N + 1, -1);
    vector<int> to(2LL * (N - 1));
    vector<int> nxt(2LL * (N - 1));
    int ec = 0;

    auto addEdge = [&](int u, int v) {
        to[ec] = v;
        nxt[ec] = head[u];
        head[u] = ec++;
    };

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        addEdge(A, B);
        addEdge(B, A);
    }

    auto bfs_far = [&](int start) -> pair<int,int> {
        vector<int> dist(N + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int far = start;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] > dist[far]) far = u;
            for (int e = head[u]; e != -1; e = nxt[e]) {
                int v = to[e];
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return {far, dist[far]};
    };

    int start = 1;
    while (start <= N && head[start] == -1) start++;
    if (start > N) {
        cout << 0 << "\n";
        return 0;
    }

    auto p1 = bfs_far(start);
    auto p2 = bfs_far(p1.first);
    cout << p2.second << "\n";
    return 0;
}
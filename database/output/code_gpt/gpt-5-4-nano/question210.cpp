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

    vector<vector<int>> adj(N);
    vector<int> indeg(N, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indeg[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) pq.push(i);
    }

    vector<int> order;
    order.reserve(N);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) pq.push(v);
        }
    }

    if ((int)order.size() != N) {
        cout << "*\n";
        return 0;
    }

    for (int x : order) cout << x << "\n";
    return 0;
}
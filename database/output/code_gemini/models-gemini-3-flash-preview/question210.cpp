/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> adj(N);
    vector<int> in_degree(N, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    result.reserve(N);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (result.size() < (size_t)N) {
        cout << "*" << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            cout << result[i] << "\n";
        }
    }

    return 0;
}
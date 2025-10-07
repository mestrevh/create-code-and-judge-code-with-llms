/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> times(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> times[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> removed(n + 1, false);
    priority_queue<pair<int, int>> pq; // (total_time, piece_index)

    for (int i = 1; i <= n; ++i) {
        pq.push({-times[i], i});
    }

    int total_time = 0;

    while (!pq.empty()) {
        auto [NegTime, u] = pq.top();
        pq.pop();
        total_time -= NegTime;

        removed[u] = true;

        for (int v : graph[u]) {
            if (!removed[v]) {
                times[v] += abs(NegTime);
                pq.push({-times[v], v});
            }
        }
    }

    cout << total_time << endl;
    return 0;
}

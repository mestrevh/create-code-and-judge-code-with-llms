/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }

    vector<vector<int>> graph(N);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dist = (trees[i].first - trees[j].first) * (trees[i].first - trees[j].first) +
                       (trees[i].second - trees[j].second) * (trees[i].second - trees[j].second);
            if (dist <= D * D) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(N, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (bool v : visited) {
        if (!v) {
            cout << 'N' << endl;
            return 0;
        }
    }
    cout << 'S' << endl;
    return 0;
}

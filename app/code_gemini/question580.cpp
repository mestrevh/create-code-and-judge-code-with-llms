/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, V;
    cin >> C >> V;

    vector<pair<int, int>> adj[C + 1];
    for (int i = 0; i < V; ++i) {
        int C1, C2, G;
        cin >> C1 >> C2 >> G;
        adj[C1].push_back({C2, G});
        adj[C2].push_back({C1, G});
    }

    vector<vector<int>> dist(C + 1, vector<int>(2, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, p] = pq.top();
        pq.pop();

        if (d > dist[u][p]) {
            continue;
        }
        
        if (u == C && p == 0) {
            break;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_p = 1 - p;

            if (dist[u][p] + weight < dist[v][new_p]) {
                dist[v][new_p] = dist[u][p] + weight;
                pq.push({dist[v][new_p], v, new_p});
            }
        }
    }

    if (dist[C][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[C][0] << endl;
    }

    return 0;
}

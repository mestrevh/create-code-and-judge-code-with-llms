/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXC = 100;
const int MAXV = 50000;
const int INF = 1e9;

struct Edge {
    int to, cost;
};

vector<Edge> graph[MAXC + 1];

void dijkstra(int start, int C, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to;
            int new_dist = d + edge.cost;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, V;
    cin >> C >> V;

    for (int i = 0; i < V; i++) {
        int C1, C2, G;
        cin >> C1 >> C2 >> G;
        graph[C1].push_back({C2, G});
        graph[C2].push_back({C1, G});
    }

    vector<int> dist(C + 1, INF);
    dijkstra(1, C, dist);

    int even_sum = INF, odd_sum = INF;
    for (int u = 1; u <= C; u++) {
        if (dist[u] < INF) {
            if (dist[u] % 2 == 0) even_sum = min(even_sum, dist[u]);
            else odd_sum = min(odd_sum, dist[u]);
        }
    }

    if (even_sum == INF && odd_sum == INF) {
        cout << -1 << endl;
    } else {
        cout << (even_sum == INF ? -1 : even_sum) << endl;
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, const vector<vector<pii>>& graph, vector<int>& dist, vector<int>& prev) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pii>> original_graph(N);
    vector<vector<pii>> reduced_graph(N);
    vector<int> original_costs;
    
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        original_graph[A].emplace_back(B, C);
        original_graph[B].emplace_back(A, C);
        reduced_graph[A].emplace_back(B, C);
        reduced_graph[B].emplace_back(A, C);
        original_costs.push_back(C);
    }
    
    int S, D;
    cin >> S >> D;

    vector<int> dist(N, numeric_limits<int>::max());
    vector<int> prev(N, -1);
    dijkstra(S, original_graph, dist, prev);
    
    int D1 = dist[D];

    dist.assign(N, numeric_limits<int>::max());
    prev.assign(N, -1);
    sort(original_costs.begin(), original_costs.end());
    
    for (int cost : original_costs) {
        for (int u = 0; u < N; ++u) {
            for (auto& edge : original_graph[u]) {
                if (edge.second == cost) {
                    reduced_graph[u].push_back(edge);
                }
            }
        }
    }
    
    dijkstra(S, reduced_graph, dist, prev);
    int D2 = dist[D];

    cout << D1 << "\n" << D2 << "\n";
    vector<int> W;

    for (int u = D; prev[u] != -1; u = prev[u]) {
        for (auto& edge : original_graph[prev[u]]) {
            if (edge.first == u) {
                W.push_back(edge.second);
                break;
            }
        }
    }
    
    reverse(W.begin(), W.end());
    
    for (int cost : W) {
        cout << cost << " ";
    }
    
    cout << "\n";
    return 0;
}

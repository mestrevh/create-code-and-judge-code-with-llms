/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, type;
};

int main() {
    int N, E, S, M;
    cin >> N >> E >> S >> M;
    vector<vector<Edge>> graph(N);
    
    for (int i = 0; i < M; ++i) {
        int A, B, T;
        cin >> A >> B >> T;
        graph[A].push_back({B, T});
    }
    
    vector<int> dist(N, INT_MAX);
    dist[E] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, E});
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (time > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.to;
            int type = edge.type;

            int wait_time = (type == 0) ? (3 - time % 3) % 3 : (time % 3);
            int arrival_time = time + 1 + wait_time;

            if (arrival_time < dist[v]) {
                dist[v] = arrival_time;
                pq.push({arrival_time, v});
            }
        }
    }
    
    int result = dist[S];
    cout << (result == INT_MAX ? '*' : result) << endl;
    return 0;
}

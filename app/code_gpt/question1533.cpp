/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, length;
};

vector<Edge> graph[100];
int M, N, W, R[100], Q[100];

void dijkstra(int start, int type, vector<int>& dist, vector<int>& cost) {
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(cost.begin(), cost.end(), INT_MAX);
    dist[start] = 0;
    cost[start] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, 0, start);
    
    while (!pq.empty()) {
        auto [currentDist, currentCost, node] = pq.top(); pq.pop();
        
        if (currentDist > dist[node]) continue;
        
        for (auto& edge : graph[node]) {
            int nextNode = edge.to;
            int length = edge.length;
            int newDist = currentDist + length;
            int newCost = currentCost + length * R[Q[node]];
            
            if (type == 'S' && (newDist < dist[nextNode] || (newDist == dist[nextNode] && newCost < cost[nextNode]))) {
                dist[nextNode] = newDist;
                cost[nextNode] = newCost;
                pq.emplace(newDist, newCost, nextNode);
            } else if (type == 'E' && (newCost < cost[nextNode] || (newCost == cost[nextNode] && newDist < dist[nextNode]))) {
                dist[nextNode] = newDist;
                cost[nextNode] = newCost;
                pq.emplace(newDist, newCost, nextNode);
            }
        }
    }
}

int main() {
    cin >> M;
    for (int i = 0; i < M; i++) cin >> R[i];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Q[i];
    cin >> W;
    
    for (int i = 0; i < W; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    
    string command;
    while (cin >> command) {
        if (command == "RIDE") {
            int C, D;
            char O;
            cin >> C >> D >> O;
            vector<int> dist(N), cost(N);
            dijkstra(C, O, dist, cost);
            cout << dist[D] << " " << cost[D] << endl;
        } else if (command == "UPDA") {
            int J, RNew;
            cin >> J >> RNew;
            R[J] = RNew;
        }
    }
    return 0;
}

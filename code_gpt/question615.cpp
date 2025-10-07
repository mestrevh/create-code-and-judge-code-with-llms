/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int to, a, b;
};

double calculate_total_max(int N, vector<Edge> graph[], double t) {
    vector<double> min_cost(N + 1, 1e18);
    min_cost[1] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 1});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (cost > min_cost[node]) continue;

        for (auto& edge : graph[node]) {
            double transaction_cost = edge.a * t + edge.b;
            if (transaction_cost < 0) continue;
            double new_cost = cost + transaction_cost;
            if (new_cost < min_cost[edge.to]) {
                min_cost[edge.to] = new_cost;
                pq.push({new_cost, edge.to});
            }
        }
    }
    return min_cost[N];
}

double find_max_tax(int N, vector<Edge> graph[]) {
    double result = 0;
    double low = 0, high = 24 * 60;
    
    for (int i = 0; i < 100; i++) {
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
        double tax1 = calculate_total_max(N, graph, mid1);
        double tax2 = calculate_total_max(N, graph, mid2);
        if (tax1 > tax2) {
            result = tax1;
            high = mid2;
        } else {
            result = tax2;
            low = mid1;
        }
    }
    return result;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<Edge> graph[N + 1];
        for (int i = 0; i < M; i++) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            graph[u].push_back({v, a, b});
            graph[v].push_back({u, a, b});
        }
        double max_tax = find_max_tax(N, graph);
        cout << fixed << setprecision(5) << max_tax << endl;
    }
    return 0;
}

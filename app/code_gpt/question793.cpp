/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, bandwidth;
    double cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int K;
    cin >> K;
    
    for (int case_num = 0; case_num < K; case_num++) {
        int N, DR;
        cin >> N >> DR;

        vector<vector<Edge>> graph(N);
        for (int i = 0; i < N; i++) {
            int D;
            cin >> D;
            for (int j = 0; j < D; j++) {
                int R;
                cin >> R;
                double B;
                cin >> B;
                double cost = 1048576.0 / B; 
                graph[i].push_back({R, B, cost});
                graph[R].push_back({i, B, cost});
            }
        }

        int M;
        cin >> M;
        vector<pair<int, int>> queries(M);
        vector<int> sizes(M);
        for (int i = 0; i < M; i++) {
            cin >> queries[i].first >> queries[i].second >> sizes[i];
        }

        cout << "caso " << case_num << ":\n";
        
        for (int i = 0; i < M; i++) {
            int S = queries[i].first;
            int T = queries[i].second;
            int size = sizes[i];

            vector<double> dist(N, INF);
            vector<vector<int>> pred(N);
            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
            
            dist[S] = 0;
            pq.push({0, S});
            
            while (!pq.empty()) {
                auto [curr_dist, node] = pq.top();
                pq.pop();

                if (curr_dist > dist[node]) continue;

                for (const auto &e : graph[node]) {
                    double new_dist = curr_dist + e.cost;
                    if (new_dist < dist[e.to]) {
                        dist[e.to] = new_dist;
                        pred[e.to] = {node};
                        pq.push({new_dist, e.to});
                    } else if (new_dist == dist[e.to]) {
                        pred[e.to].push_back(node);
                    }
                }
            }
            
            vector<int> route1, route2;
            if (dist[DR] < INF) {
                int u = DR;
                while (u != S) {
                    route1.push_back(u);
                    if (pred[u].empty()) break;
                    u = pred[u][0];
                }
                route1.push_back(S);
                reverse(route1.begin(), route1.end());
            }

            if (dist[T] < INF) {
                int u = T;
                while (u != DR) {
                    route2.push_back(u);
                    if (pred[u].empty()) break;
                    u = pred[u][0];
                }
                route2.push_back(DR);
                reverse(route2.begin(), route2.end());
            }

            double total_time = 0;
            if (!route1.empty() && !route2.empty()) {
                int intermediate_count = (route1.size() - 1) + (route2.size() - 1);
                
                total_time += size / graph[S][route1[1]].bandwidth;
                total_time += size / graph[DR][route2[1]].bandwidth;

                cout << intermediate_count << " " << (int)total_time << "\n";
            } else {
                cout << 0 << " " << 0 << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

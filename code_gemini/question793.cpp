/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <set>
#include <algorithm>
#include <string>

const long long INF = std::numeric_limits<long long>::max();
const int MAXN = 257;

std::vector<std::pair<int, int>> adj[MAXN];
int bandwidth[MAXN][MAXN];
long long dist[MAXN];
int pred[MAXN];
int N;

void dijkstra(int start_node) {
    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        pred[i] = -1;
    }

    dist[start_node] = 0;
    
    using State = std::pair<long long, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    pq.push({0, start_node});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second;
            
            if (dist[u] == INF) continue;

            long long new_dist = dist[u] + cost;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pred[v] = u;
                pq.push({new_dist, v});
            } else if (new_dist == dist[v]) {
                if (pred[v] == -1 || u < pred[v]) {
                    pred[v] = u;
                    pq.push({new_dist, v});
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int case_num = 0;
    int DR;

    while (std::cin >> N >> DR) {
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
            for (int j = 0; j < N; ++j) {
                bandwidth[i][j] = 0;
            }
        }

        long long cost_numerator = 1LL << 20;

        for (int i = 0; i < N; ++i) {
            int D;
            std::cin >> D;
            for (int j = 0; j < D; ++j) {
                int R, B;
                std::cin >> R >> B;
                if (B > 0) {
                    int cost = cost_numerator / B;
                    adj[i].push_back({R, cost});
                    adj[R].push_back({i, cost});
                    bandwidth[i][R] = B;
                    bandwidth[R][i] = B;
                }
            }
        }

        dijkstra(DR);

        int M;
        std::cin >> M;
        
        std::cout << "caso " << case_num++ << ":\n";

        for (int i = 0; i < M; ++i) {
            int S, T;
            long long Z;
            std::cin >> S >> T >> Z;

            std::vector<int> path_s_to_dr;
            if (dist[S] != INF) {
                int curr = S;
                while (true) {
                    path_s_to_dr.push_back(curr);
                    if (curr == DR) break;
                    if (pred[curr] == -1) break;
                    curr = pred[curr];
                }
                std::reverse(path_s_to_dr.begin(), path_s_to_dr.end());
            }
            
            std::vector<int> path_dr_to_t;
            if (dist[T] != INF) {
                int curr = T;
                while(true) {
                    path_dr_to_t.push_back(curr);
                    if (curr == DR) break;
                    if (pred[curr] == -1) break;
                    curr = pred[curr];
                }
                // path_dr_to_t is from T to DR, so it is reversed to get DR to T
                std::reverse(path_dr_to_t.begin(), path_dr_to_t.end());
            }

            std::set<int> path_nodes;
            for(int node : path_s_to_dr) path_nodes.insert(node);
            for(int node : path_dr_to_t) path_nodes.insert(node);

            path_nodes.erase(S);
            path_nodes.erase(T);
            int H = path_nodes.size();

            long long total_time = 0;

            for (size_t j = 0; j + 1 < path_s_to_dr.size(); ++j) {
                int u = path_s_to_dr[j];
                int v = path_s_to_dr[j+1];
                int B = bandwidth[u][v];
                if (B > 0) {
                    total_time += Z / B;
                }
            }
            
            for (size_t j = 0; j + 1 < path_dr_to_t.size(); ++j) {
                int u = path_dr_to_t[j];
                int v = path_dr_to_t[j+1];
                int B = bandwidth[u][v];
                if (B > 0) {
                    total_time += Z / B;
                }
            }
            
            std::cout << H << " " << total_time << "\n";
        }
         std::cout << "\n";
    }

    return 0;
}

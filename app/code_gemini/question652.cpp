/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

#define MAX_V 5151
#define INF 1e9

int N, M, A;
std::vector<std::tuple<int, int, int>> flights;
int V_flow;
int capacity[MAX_V][MAX_V];
int parent[MAX_V];

int node_idx(int airport, int day) {
    return day * N + (airport - 1);
}

bool bfs(int s, int t) {
    for (int i = 0; i < V_flow; ++i) {
        parent[i] = -1;
    }
    std::queue<int> q;
    q.push(s);
    parent[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V_flow; ++v) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                if (v == t) {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}

int edmonds_karp(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        int path_flow = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, capacity[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

bool check(int D) {
    if (D < 0) return false;
    
    V_flow = N * (D + 1) + 2;
    if (V_flow > MAX_V) return false;

    int s = V_flow - 2;
    int t = V_flow - 1;
    
    for (int i = 0; i < V_flow; ++i) {
        for (int j = 0; j < V_flow; ++j) {
            capacity[i][j] = 0;
        }
    }

    capacity[s][node_idx(1, 0)] = A;

    for (int d = 0; d <= D; ++d) {
        capacity[node_idx(N, d)][t] = A;
    }

    for (int d = 0; d < D; ++d) {
        for (int u = 1; u <= N; ++u) {
            capacity[node_idx(u, d)][node_idx(u, d + 1)] = A;
        }
        for (const auto& flight : flights) {
            int u, v, seats;
            std::tie(u, v, seats) = flight;
            capacity[node_idx(u, d)][node_idx(v, d + 1)] = seats;
        }
    }

    return edmonds_karp(s, t) >= A;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> N >> M >> A && (N != 0 || M != 0 || A != 0)) {
        flights.clear();
        flights.reserve(M);
        for (int i = 0; i < M; ++i) {
            int O, D, S;
            std::cin >> O >> D >> S;
            flights.emplace_back(O, D, S);
        }

        if (A == 0) {
            std::cout << 0 << "\n";
            continue;
        }

        int low = 0, high = N + A;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        std::cout << ans << "\n";
    }

    return 0;
}

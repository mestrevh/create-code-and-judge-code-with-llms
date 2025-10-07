/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>

const int MAXN_LOC = 5005;
const int MAXN_CITY = 105;
const int INF = std::numeric_limits<int>::max();

int location_to_city[MAXN_LOC];
int city_dist[MAXN_CITY][MAXN_CITY];

struct CityState {
    int dist;
    int u;
    bool operator>(const CityState& other) const {
        return dist > other.dist;
    }
};

struct FlowEdge {
    int to;
    int capacity;
    int rev;
};
std::vector<FlowEdge> flow_adj[MAXN_LOC];
int level[MAXN_LOC];
int iter[MAXN_LOC];

void add_flow_edge(int u, int v, int cap) {
    flow_adj[u].push_back({v, cap, (int)flow_adj[v].size()});
    flow_adj[v].push_back({u, 0, (int)flow_adj[u].size() - 1});
}

bool bfs_dinic(int s, int t, int n_nodes) {
    std::fill(level, level + n_nodes, -1);
    std::queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& edge : flow_adj[u]) {
            if (edge.capacity > 0 && level[edge.to] < 0) {
                level[edge.to] = level[u] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs_dinic(int u, int t, int f) {
    if (u == t) return f;
    for (int& i = iter[u]; i < flow_adj[u].size(); ++i) {
        FlowEdge& e = flow_adj[u][i];
        if (e.capacity > 0 && level[u] < level[e.to]) {
            int d = dfs_dinic(e.to, t, std::min(f, e.capacity));
            if (d > 0) {
                e.capacity -= d;
                flow_adj[e.to][e.rev].capacity += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow_dinic(int s, int t, int n_nodes) {
    int flow = 0;
    while (bfs_dinic(s, t, n_nodes)) {
        std::fill(iter, iter + n_nodes, 0);
        int f;
        while ((f = dfs_dinic(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

struct OriginalEdge {
    int u, v, c, d;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, m;
    std::cin >> n >> k;
    std::cin.ignore();

    for (int i = 0; i < k; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int loc;
        while (ss >> loc) {
            location_to_city[loc] = i;
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            city_dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    std::cin >> m;
    std::vector<OriginalEdge> all_edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].c >> all_edges[i].d;
        int cu = location_to_city[all_edges[i].u];
        int cv = location_to_city[all_edges[i].v];
        if (cu != cv) {
            city_dist[cu][cv] = std::min(city_dist[cu][cv], all_edges[i].d);
        }
    }

    int s_loc, t_loc;
    std::cin >> s_loc >> t_loc;

    int s_city = location_to_city[s_loc];
    int t_city = location_to_city[t_loc];

    std::vector<int> d_city(k, INF);
    std::vector<int> pred_city(k, -1);
    d_city[s_city] = 0;

    std::priority_queue<CityState, std::vector<CityState>, std::greater<CityState>> pq;
    pq.push({0, s_city});

    while (!pq.empty()) {
        CityState current = pq.top();
        pq.pop();
        int u = current.u;
        int d = current.dist;

        if (d > d_city[u]) continue;
        if (u == t_city) break;

        for (int v = 0; v < k; ++v) {
            if (u == v || city_dist[u][v] == INF) continue;
            if (d_city[u] + city_dist[u][v] < d_city[v]) {
                d_city[v] = d_city[u] + city_dist[u][v];
                pred_city[v] = u;
                pq.push({d_city[v], v});
            }
        }
    }

    std::cout << d_city[t_city] << std::endl;

    std::vector<int> city_path;
    int curr_city = t_city;
    if (d_city[t_city] != INF) {
        while (curr_city != -1) {
            city_path.push_back(curr_city);
            curr_city = pred_city[curr_city];
        }
    }
    std::reverse(city_path.begin(), city_path.end());

    std::vector<bool> in_path(k, false);
    std::map<int, int> city_to_path_idx;
    for(size_t i = 0; i < city_path.size(); ++i) {
        in_path[city_path[i]] = true;
        city_to_path_idx[city_path[i]] = i;
    }

    for (const auto& edge : all_edges) {
        int u = edge.u;
        int v = edge.v;
        int c = edge.c;
        int cu = location_to_city[u];
        int cv = location_to_city[v];

        if (in_path[cu] && in_path[cv]) {
            if (cu == cv) {
                add_flow_edge(u, v, c);
            } else {
                if (city_to_path_idx.count(cu) && city_to_path_idx.count(cv) &&
                    city_to_path_idx.at(cv) == city_to_path_idx.at(cu) + 1) {
                    add_flow_edge(u, v, c);
                }
            }
        }
    }
    
    std::cout << max_flow_dinic(s_loc, t_loc, n) << std::endl;

    return 0;
}

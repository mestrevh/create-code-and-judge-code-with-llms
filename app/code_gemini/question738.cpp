/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
#include <utility>
#include <functional>

void solve(int case_num) {
    std::string o_str, d_str;
    int y, m;
    std::cin >> o_str >> d_str >> y >> m;

    std::map<std::string, int> name_to_id;
    std::vector<std::vector<std::pair<int, int>>> adj(1005);
    int next_id = 0;

    auto get_id = [&](const std::string& name) -> int {
        if (name_to_id.find(name) == name_to_id.end()) {
            name_to_id[name] = next_id++;
        }
        return name_to_id[name];
    };

    int start_node = get_id(o_str);
    int end_node = get_id(d_str);

    for (int i = 0; i < m; ++i) {
        std::string a_str, b_str;
        int x;
        std::cin >> a_str >> b_str >> x;
        int u = get_id(a_str);
        int v = get_id(b_str);
        adj[u].push_back({v, x});
    }

    int num_terminals = next_id;
    
    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> dist(num_terminals, INF);
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        long long current_time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_time > dist[u]) {
            continue;
        }

        if (u == end_node) {
            break;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int x = edge.second;
            
            long long wait_time = (x - (current_time % x)) % x;
            long long new_time = current_time + wait_time + y;

            if (new_time < dist[v]) {
                dist[v] = new_time;
                pq.push({new_time, v});
            }
        }
    }

    std::cout << "Caso #" << case_num << ": ";
    if (dist[end_node] == INF) {
        std::cout << "Destino inalcancavel" << std::endl;
    } else {
        std::cout << dist[end_node] << " anticalmas" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}

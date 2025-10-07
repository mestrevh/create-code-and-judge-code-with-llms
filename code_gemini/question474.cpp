/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

void solve(int case_num) {
    int m, n, p;
    std::cin >> m >> n >> p;

    std::map<std::string, int> port_to_id;
    for (int i = 0; i < m; ++i) {
        std::string port_name;
        std::cin >> port_name;
        port_to_id[port_name] = i;
    }

    std::vector<std::vector<int>> adj(m);
    for (int i = 0; i < n; ++i) {
        std::string port1, port2;
        std::cin >> port1 >> port2;
        int u = port_to_id[port1];
        int v = port_to_id[port2];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::cout << "DATA SET  " << case_num << std::endl << std::endl;

    for (int i = 0; i < p; ++i) {
        int size;
        std::string start_port, end_port;
        std::cin >> size >> start_port >> end_port;

        int start_id = port_to_id[start_port];
        int end_id = port_to_id[end_port];

        std::queue<int> q;
        std::vector<int> dist(m, -1);

        q.push(start_id);
        dist[start_id] = 0;
        
        int path_len = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == end_id) {
                path_len = dist[u];
                break;
            }

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (path_len == -1) {
            std::cout << "NO SHIPMENT POSSIBLE" << std::endl;
        } else {
            long long cost = (long long)size * path_len * 100;
            std::cout << "$" << cost << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d;
    std::cin >> d;

    std::cout << "SHIPPING ROUTES OUTPUT" << std::endl << std::endl;

    for (int i = 1; i <= d; ++i) {
        solve(i);
        if (i < d) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl << "END OF OUTPUT" << std::endl;

    return 0;
}

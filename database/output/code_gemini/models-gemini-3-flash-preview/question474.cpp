/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Adjacency list and distance array for ports.
// Ports are indexed from 0 to M-1. Max M is 7000.
int dists[7005];
vector<int> adj[7005];

void solve() {
    int D;
    // Read the number of data sets.
    if (!(cin >> D)) return;

    cout << "SHIPPING ROUTES OUTPUT\n";

    for (int d = 1; d <= D; ++d) {
        int M, N, P;
        // Read number of ports (M), number of aquaways (N), and number of quotes (P).
        if (!(cin >> M >> N >> P)) break;

        // Map each port name to a unique integer index.
        unordered_map<string, int> port_map;
        port_map.reserve(M);
        for (int i = 0; i < M; ++i) {
            string name;
            cin >> name;
            port_map[name] = i;
            adj[i].clear();
        }

        // Build the graph using the adjacency list.
        for (int i = 0; i < N; ++i) {
            string u_s, v_s;
            cin >> u_s >> v_s;
            auto it_u = port_map.find(u_s);
            auto it_v = port_map.find(v_s);
            if (it_u != port_map.end() && it_v != port_map.end()) {
                int u = it_u->second;
                int v = it_v->second;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        // Print header for the data set.
        cout << "\nDATA SET  " << d << "\n\n";

        // Process each quote request.
        for (int i = 0; i < P; ++i) {
            int Z;
            string start_s, end_s;
            cin >> Z >> start_s >> end_s;

            auto it_start = port_map.find(start_s);
            auto it_end = port_map.find(end_s);

            // Basic check if ports exist.
            if (it_start == port_map.end() || it_end == port_map.end()) {
                cout << "NO SHIPMENT POSSIBLE\n";
                continue;
            }

            int start_idx = it_start->second;
            int end_idx = it_end->second;

            // Perform Breadth-First Search to find the shortest path in an unweighted graph.
            int result_dist = -1;
            for (int j = 0; j < M; ++j) dists[j] = -1;

            queue<int> q;
            q.push(start_idx);
            dists[start_idx] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (u == end_idx) {
                    result_dist = dists[u];
                    break;
                }

                int next_dist = dists[u] + 1;
                for (int v : adj[u]) {
                    if (dists[v] == -1) {
                        dists[v] = next_dist;
                        q.push(v);
                    }
                }
            }

            // Calculate cost or report failure.
            if (result_dist != -1) {
                // Cost = Z * number of aquaways * 100.
                cout << "$" << (long long)Z * result_dist * 100 << "\n";
            } else {
                cout << "NO SHIPMENT POSSIBLE\n";
            }
        }
    }
    // End of the entire program output.
    cout << "\nEND OF OUTPUT\n";
}

int main() {
    // Fast I/O optimization for performance in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
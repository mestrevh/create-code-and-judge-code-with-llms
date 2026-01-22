/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    int case_num = 1;

    while (cin >> N >> X) {
        int num_walls = 2 * (N * N - N);
        vector<int> forces(num_walls);
        for (int i = 0; i < num_walls; ++i) {
            cin >> forces[i];
        }

        int num_cells = N * N;
        vector<vector<pair<int, int>>> adj(num_cells);

        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                int current_cell = r * N + c;

                if (c < N - 1) {
                    int right_cell = current_cell + 1;
                    int wall_idx = r * (2 * N - 1) + c;
                    int weight = forces[wall_idx];
                    adj[current_cell].push_back({right_cell, weight});
                    adj[right_cell].push_back({current_cell, weight});
                }

                if (r < N - 1) {
                    int bottom_cell = current_cell + N;
                    int wall_idx = r * (2 * N - 1) + (N - 1) + c;
                    int weight = forces[wall_idx];
                    adj[current_cell].push_back({bottom_cell, weight});
                    adj[bottom_cell].push_back({current_cell, weight});
                }
            }
        }

        const long long INF = numeric_limits<long long>::max();
        vector<long long> dist(num_cells, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[X] = 0;
        pq.push({0, X});

        long long min_force = -1;

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) {
                continue;
            }

            int r = u / N;
            int c = u % N;
            if (r == 0 || r == N - 1 || c == 0 || c == N - 1) {
                min_force = d;
                break;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "caso " << case_num++ << ": " << min_force << endl;
    }

    return 0;
}

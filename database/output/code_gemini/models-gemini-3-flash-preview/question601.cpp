/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int dist;
};

struct Line {
    int min_terminal;
    vector<int> terminals;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int case_num = 0;
    while (cin >> N >> M) {
        vector<vector<Edge>> adj(N);
        vector<int> degree(N, 0);
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            if (u < N && v < N) {
                adj[u].push_back({v, d});
                adj[v].push_back({u, d});
            }
        }

        vector<bool> visited(N, false);
        vector<Line> lines;

        for (int i = 0; i < N; ++i) {
            if (!visited[i] && !adj[i].empty()) {
                vector<int> component;
                vector<int> q;
                q.push_back(i);
                visited[i] = true;
                int head = 0;
                while (head < (int)q.size()) {
                    int u = q[head++];
                    component.push_back(u);
                    for (auto& edge : adj[u]) {
                        if (!visited[edge.to]) {
                            visited[edge.to] = true;
                            q.push_back(edge.to);
                        }
                    }
                }

                vector<int> terminals;
                for (int u : component) {
                    if (adj[u].size() != 2) {
                        terminals.push_back(u);
                    }
                }

                if (!terminals.empty()) {
                    sort(terminals.begin(), terminals.end());
                    lines.push_back({terminals[0], terminals});
                }
            }
        }

        sort(lines.begin(), lines.end(), [](const Line& a, const Line& b) {
            return a.min_terminal < b.min_terminal;
        });

        cout << "caso " << case_num++ << "\n";
        for (auto& line : lines) {
            vector<long long> dist(N, INF);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            int start_node = line.terminals[0];
            dist[start_node] = 0;
            pq.push({0, start_node});

            while (!pq.empty()) {
                long long d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d > dist[u]) continue;

                for (auto& edge : adj[u]) {
                    if (dist[u] + edge.dist < dist[edge.to]) {
                        dist[edge.to] = dist[u] + edge.dist;
                        pq.push({dist[edge.to], edge.to});
                    }
                }
            }

            for (int j = 0; j < (int)line.terminals.size(); ++j) {
                cout << dist[line.terminals[j]] << (j == (int)line.terminals.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
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
const long long COST_FACTOR = 1048576LL;

struct Edge {
    int to;
    int bandwidth;
    long long cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, DR;
    int caseNum = 0;
    while (cin >> N >> DR) {
        static int bw_matrix[256][256];
        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < 256; ++j) {
                bw_matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < N; ++i) {
            int D;
            cin >> D;
            for (int j = 0; j < D; ++j) {
                int R, B;
                cin >> R >> B;
                if (B > bw_matrix[i][R]) {
                    bw_matrix[i][R] = B;
                }
            }
        }

        vector<vector<Edge>> best_adj(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (bw_matrix[i][j] > 0) {
                    best_adj[i].push_back({j, bw_matrix[i][j], COST_FACTOR / bw_matrix[i][j]});
                }
            }
        }

        vector<vector<long long>> dist(N, vector<long long>(N, INF));
        vector<vector<int>> parent(N, vector<int>(N, -1));

        for (int s = 0; s < N; ++s) {
            dist[s][s] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, s});
            while (!pq.empty()) {
                long long d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (d > dist[s][u]) continue;
                for (auto& edge : best_adj[u]) {
                    int v = edge.to;
                    long long w = edge.cost;
                    if (dist[s][v] > dist[s][u] + w) {
                        dist[s][v] = dist[s][u] + w;
                        parent[s][v] = u;
                        pq.push({dist[s][v], v});
                    } else if (dist[s][v] == dist[s][u] + w) {
                        if (parent[s][v] == -1 || u < parent[s][v]) {
                            parent[s][v] = u;
                        }
                    }
                }
            }
        }

        int M;
        cin >> M;
        if (caseNum > 0) cout << endl;
        cout << "caso " << caseNum++ << ":" << endl;
        for (int i = 0; i < M; ++i) {
            int S, T;
            long long Z;
            cin >> S >> T >> Z;

            vector<int> full_path;
            if (dist[S][DR] != INF) {
                vector<int> path1;
                int curr = DR;
                while (curr != S && curr != -1) {
                    path1.push_back(curr);
                    curr = parent[S][curr];
                }
                path1.push_back(S);
                reverse(path1.begin(), path1.end());
                full_path = path1;
            }

            if (dist[DR][T] != INF) {
                vector<int> path2;
                int curr = T;
                while (curr != DR && curr != -1) {
                    path2.push_back(curr);
                    curr = parent[DR][curr];
                }
                reverse(path2.begin(), path2.end());
                for (int node : path2) {
                    full_path.push_back(node);
                }
            }

            int H = 0;
            if (full_path.size() >= 2) {
                H = (int)full_path.size() - 2;
            }

            long long TT = 0;
            for (int j = 0; j + 1 < (int)full_path.size(); ++j) {
                int u = full_path[j];
                int v = full_path[j + 1];
                TT += (Z / bw_matrix[u][v]);
            }
            cout << H << " " << TT << endl;
        }
    }
    return 0;
}
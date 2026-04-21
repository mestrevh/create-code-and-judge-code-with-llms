/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, A;
    if (!(cin >> V >> A)) return 0;

    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));
    vector<long long> adj_sum(V + 1, 0);

    for (int i = 1; i <= V; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < A; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 1 || u > V || v < 1 || v > V) continue;
        if (u == v) {
            adj_sum[u] += v;
        } else {
            if (w < dist[u][v]) {
                dist[u][v] = dist[v][u] = w;
            }
            adj_sum[u] += v;
            adj_sum[v] += u;
        }
    }

    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= V; ++j) {
                if (dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<int> red, blue;
    for (int i = 1; i <= V; ++i) {
        if (adj_sum[i] % 2 == 0) {
            red.push_back(i);
        } else {
            blue.push_back(i);
        }
    }

    auto findMaxPair = [&](const vector<int>& nodes) {
        int maxDist = -1;
        pair<int, int> bestPair = {0, 0};
        for (int i = 0; i < (int)nodes.size(); ++i) {
            for (int j = i + 1; j < (int)nodes.size(); ++j) {
                int u = nodes[i];
                int v = nodes[j];
                int d = dist[u][v];
                
                if (d > maxDist) {
                    maxDist = d;
                    bestPair = {min(u, v), max(u, v)};
                } else if (d == maxDist) {
                    pair<int, int> currentPair = {min(u, v), max(u, v)};
                    if (bestPair.first == 0 || currentPair < bestPair) {
                        bestPair = currentPair;
                    }
                }
            }
        }
        return bestPair;
    };

    pair<int, int> resRed = findMaxPair(red);
    pair<int, int> resBlue = findMaxPair(blue);

    if (resRed.first != 0) {
        cout << resRed.first << " " << resRed.second << "\n";
    }
    if (resBlue.first != 0) {
        cout << resBlue.first << " " << resBlue.second << "\n";
    }

    return 0;
}
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

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = dist[v][u] = w;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < N; ++j) {
                if (dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int min_max_dist = INF;

    for (int i = 0; i < N; ++i) {
        int current_max_dist = 0;
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] > current_max_dist) {
                current_max_dist = dist[i][j];
            }
        }
        if (current_max_dist < min_max_dist) {
            min_max_dist = current_max_dist;
        }
    }

    cout << min_max_dist << endl;

    return 0;
}
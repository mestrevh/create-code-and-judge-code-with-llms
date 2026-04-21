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

    int N, E;
    while (cin >> N >> E && N != 0) {
        vector<vector<int>> orig(N + 1, vector<int>(N + 1, INF));
        for (int i = 1; i <= N; ++i) {
            orig[i][i] = 0;
        }

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            if (w < orig[u][v]) {
                orig[u][v] = w;
            }
        }

        vector<vector<int>> dist = orig;
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 1; j <= N; ++j) {
                    if (dist[k][j] < INF) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        vector<vector<int>> fdist(N + 1, vector<int>(N + 1, INF));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][j] < INF && dist[j][i] < INF) {
                    fdist[i][j] = 0;
                } else {
                    fdist[i][j] = orig[i][j];
                }
            }
        }

        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                if (fdist[i][k] == INF) continue;
                for (int j = 1; j <= N; ++j) {
                    if (fdist[k][j] < INF) {
                        if (fdist[i][k] + fdist[k][j] < fdist[i][j]) {
                            fdist[i][j] = fdist[i][k] + fdist[k][j];
                        }
                    }
                }
            }
        }

        int K;
        cin >> K;
        for (int i = 0; i < K; ++i) {
            int o, d;
            cin >> o >> d;
            if (o < 1 || o > N || d < 1 || d > N || fdist[o][d] >= INF) {
                cout << "Nao e possivel entregar a carta\n";
            } else {
                cout << fdist[o][d] << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}


/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int INF = 1e9;
const int MAXV = 101;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, A;
    std::cin >> V >> A;

    std::vector<int> adj[MAXV];
    int dist[MAXV][MAXV];

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < A; ++i) {
        int S, D, C;
        std::cin >> S >> D >> C;
        adj[S].push_back(D);
        adj[D].push_back(S);
        dist[S][D] = std::min(dist[S][D], C);
        dist[D][S] = std::min(dist[D][S], C);
    }

    std::vector<int> color(V + 1);
    for (int i = 1; i <= V; ++i) {
        long long sum = 0;
        for (int neighbor : adj[i]) {
            sum += neighbor;
        }
        if (sum % 2 == 0) {
            color[i] = 0; // Red
        } else {
            color[i] = 1; // Blue
        }
    }

    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int max_red_dist = -1;
    int red_u = -1, red_v = -1;

    int max_blue_dist = -1;
    int blue_u = -1, blue_v = -1;

    for (int i = 1; i <= V; ++i) {
        for (int j = i + 1; j <= V; ++j) {
            if (dist[i][j] != INF && color[i] == color[j]) {
                if (color[i] == 0) { 
                    if (dist[i][j] > max_red_dist) {
                        max_red_dist = dist[i][j];
                        red_u = i;
                        red_v = j;
                    }
                } else { 
                    if (dist[i][j] > max_blue_dist) {
                        max_blue_dist = dist[i][j];
                        blue_u = i;
                        blue_v = j;
                    }
                }
            }
        }
    }

    std::cout << red_u << " " << red_v << "\n";
    std::cout << blue_u << " " << blue_v << "\n";

    return 0;
}

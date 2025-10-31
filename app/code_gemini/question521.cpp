/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C;
    std::cin >> C;

    for (int k = 0; k < C; ++k) {
        int N, S;
        std::cin >> N >> S;

        std::vector<std::vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            int D;
            std::cin >> D;
            adj[i].resize(D);
            for (int j = 0; j < D; ++j) {
                std::cin >> adj[i][j];
            }
        }

        std::vector<int> dist(N, -1);
        std::queue<int> q;

        dist[S] = 0;
        q.push(S);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int dmax = 0;
        for (int i = 0; i < N; ++i) {
            if (dist[i] > dmax) {
                dmax = dist[i];
            }
        }

        int nmax = 0;
        for (int i = 0; i < N; ++i) {
            if (dist[i] == dmax) {
                nmax++;
            }
        }

        std::cout << k << " " << dmax << " " << nmax << std::endl;
    }

    return 0;
}

/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    while (cin >> N >> E) {
        if (N == 0) break;

        const long long INF = (1LL << 60);
        vector<vector<long long>> dist(N, vector<long long>(N, INF));
        for (int i = 0; i < N; i++) dist[i][i] = 0;

        vector<int> country(N, -1);
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            cin >> X >> Y >> H;
            --X; --Y;
            dist[X][Y] = min(dist[X][Y], (long long)H);
        }

        vector<int> parent(N);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> findp = [&](int a) {
            return parent[a] == a ? a : parent[a] = findp(parent[a]);
        };
        auto unite = [&](int a, int b) {
            a = findp(a); b = findp(b);
            if (a != b) parent[b] = a;
        };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (dist[i][j] < INF) {
                    unite(i, j);
                }
            }
        }

        vector<vector<long long>> dist2 = dist;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int ci = findp(i), cj = findp(j);
                if (ci == cj) {
                    if (dist2[i][j] > 0) dist2[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                long long dik = dist2[i][k];
                if (dik == INF) continue;
                for (int j = 0; j < N; j++) {
                    long long nd = dik + dist2[k][j];
                    if (nd < dist2[i][j]) dist2[i][j] = nd;
                }
            }
        }

        int K;
        cin >> K;
        for (int qi = 0; qi < K; qi++) {
            int O, D;
            cin >> O >> D;
            --O; --D;
            if (dist2[O][D] >= INF/2) {
                cout << "Nao e possivel entregar a carta\n";
            } else {
                cout << dist2[O][D] << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
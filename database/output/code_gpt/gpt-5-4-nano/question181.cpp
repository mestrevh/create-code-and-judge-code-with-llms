/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    const long long INF = (1LL<<60);
    vector<vector<long long>> dist(N, vector<long long>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        if (W < dist[U][V]) {
            dist[U][V] = dist[V][U] = W;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            long long dik = dist[i][k];
            if (dik == INF) continue;
            for (int j = 0; j < N; j++) {
                long long nd = dik + dist[k][j];
                if (nd < dist[i][j]) dist[i][j] = nd;
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < N; i++) {
        long long mx = 0;
        for (int j = 0; j < N; j++) mx = max(mx, dist[i][j]);
        ans = min(ans, mx);
    }

    cout << ans << "\n";
    return 0;
}
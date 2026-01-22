/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> dist(N, vector<int>(N, INF));
    
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        dist[U][V] = min(dist[U][V], W);
        dist[V][U] = min(dist[V][U], W);
    }
    
    for (int i = 0; i < N; i++) dist[i][i] = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int result = INF;
    for (int i = 0; i < N; i++) {
        int maxDist = 0;
        for (int j = 0; j < N; j++) {
            if (dist[j][i] != INF) {
                maxDist = max(maxDist, dist[j][i]);
            }
        }
        result = min(result, maxDist);
    }
    
    cout << result << endl;
    return 0;
}

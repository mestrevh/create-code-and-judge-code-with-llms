/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 505;
int dist[MAXN][MAXN];

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, e;
    while (cin >> n >> e, n) {
        memset(dist, 0x3f, sizeof dist);
        for (int i = 1; i <= n; i++) dist[i][i] = 0;

        for (int i = 0; i < e; i++) {
            int x, y, h;
            cin >> x >> y >> h;
            dist[x][y] = min(dist[x][y], h);
        }

        floydWarshall(n);
        
        int k;
        cin >> k;
        while (k--) {
            int o, d;
            cin >> o >> d;
            if (dist[o][d] == INT_MAX) cout << "Nao e possivel entregar a carta\n";
            else cout << dist[o][d] << "\n";
        }
        cout << "\n";
    }
    return 0;
}

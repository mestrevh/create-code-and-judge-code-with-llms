/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                adj[x][y] = adj[y][x] = z;
            }
        }

        int max_entrosamento = -1;
        int best_i = 1, best_j = 2, best_k = 3;

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    int current_entrosamento = adj[i][j] + adj[j][k] + adj[i][k];
                    if (current_entrosamento > max_entrosamento) {
                        max_entrosamento = current_entrosamento;
                        best_i = i;
                        best_j = j;
                        best_k = k;
                    }
                }
            }
        }

        cout << best_i << " " << best_j << " " << best_k << "\n";
    }

    return 0;
}
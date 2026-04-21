/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int adj[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u][v] = w;
            adj[v][u] = w;
        }

        int max_sum = -1;
        int b_i = 1, b_j = 2, b_k = 3;

        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int k = j + 1; k <= n; k++) {
                    int sum = adj[i][j] + adj[i][k] + adj[j][k];
                    if (sum > max_sum) {
                        max_sum = sum;
                        b_i = i;
                        b_j = j;
                        b_k = k;
                    }
                }
            }
        }

        cout << b_i << " " << b_j << " " << b_k << "\n";
    }

    return 0;
}
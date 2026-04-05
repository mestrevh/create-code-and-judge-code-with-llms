/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

static double M[305][305];
static vector<int> adj[605];
static vector<int> subtree_pilots[605];
static double dp[605][305];
static bool is_child[605];

void solve(int u, int N) {
    if (u <= N) {
        subtree_pilots[u].push_back(u);
        dp[u][u] = 1.0;
        return;
    }

    int L = adj[u][0];
    int R = adj[u][1];

    solve(L, N);
    solve(R, N);

    for (int i : subtree_pilots[L]) {
        double sum_j = 0;
        for (int j : subtree_pilots[R]) {
            sum_j += dp[R][j] * M[i][j];
        }
        dp[u][i] = dp[L][i] * sum_j;
        subtree_pilots[u].push_back(i);
    }

    for (int j : subtree_pilots[R]) {
        double sum_i = 0;
        for (int i : subtree_pilots[L]) {
            sum_i += dp[L][i] * M[j][i];
        }
        dp[u][j] = dp[R][j] * sum_i;
        subtree_pilots[u].push_back(j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> M[i][j];
            }
        }

        int max_node = 2 * N - 1;
        for (int i = 0; i <= max_node; ++i) {
            adj[i].clear();
            subtree_pilots[i].clear();
            is_child[i] = false;
            for (int j = 0; j <= N; ++j) {
                dp[i][j] = 0.0;
            }
        }

        for (int i = N + 1; i <= max_node; ++i) {
            int a, b;
            cin >> a >> b;
            adj[i].push_back(a);
            adj[i].push_back(b);
            is_child[a] = true;
            is_child[b] = true;
        }

        int root = -1;
        for (int i = N + 1; i <= max_node; ++i) {
            if (!is_child[i]) {
                root = i;
                break;
            }
        }

        if (root != -1) {
            solve(root, N);
            cout << fixed << setprecision(6) << dp[root][1] << endl;
        } else if (N == 1) {
            cout << fixed << setprecision(6) << 1.000000 << endl;
        }
    }

    return 0;
}
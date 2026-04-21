/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int outi, outj;
    cin >> outi >> outj;

    vector<vector<long long>> a(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    outi--; outj--;

    vector<vector<int>> dp(N, vector<int>(N, -1));
    auto inside = [&](int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; };

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    function<int(int,int)> solve = [&](int x, int y) -> int {
        if (x == outi && y == outj) return dp[x][y] = 0;
        int &res = dp[x][y];
        if (res != -1) return res;
        res = -1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!inside(nx, ny)) continue;
            if (a[nx][ny] == a[x][y] + 1) {
                int t = solve(nx, ny);
                if (t != -1) res = max(res, t + 1);
            }
        }
        return res;
    };

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v = solve(i, j);
            if (v != -1) ans = max(ans, v);
        }
    }

    cout << "Numero de passos do maior caminho: " << ans << "\n";
    return 0;
}
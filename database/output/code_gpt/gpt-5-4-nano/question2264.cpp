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

    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    vector<vector<int>> freeCell(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            freeCell[i][j] = (a[i][j] == 0);

    vector<vector<int>> dp;
    int ans = 0;
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (!freeCell[x][y]) continue;
            int score = 0;
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                while (nx >= 0 && nx < N && ny >= 0 && ny < N && freeCell[nx][ny]) {
                    score++;
                    nx += dx[d];
                    ny += dy[d];
                }
            }
            ans = max(ans, score);
        }
    }

    cout << ans << "\n";
    return 0;
}
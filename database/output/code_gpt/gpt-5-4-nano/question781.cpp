/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> a(L, vector<int>(C, 0));
    vector<vector<bool>> used(L, vector<bool>(C, false));

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    int r = 0, c = 0;
    int dir = 0;
    int cur = 1;

    for (int step = 0; step < L * C; step++) {
        a[r][c] = cur;
        used[r][c] = true;
        cur++;

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 || nr >= L || nc < 0 || nc >= C || used[nr][nc]) {
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr; c = nc;
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (j) cout << ' ';
            cout << setw(3) << setfill('0') << a[i][j];
        }
        if (i + 1 < L) cout << "\n";
    }

    return 0;
}
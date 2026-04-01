/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int grid[25][25];
int dr[] = {-1, -1, 1, 1};
int dc[] = {-1, 1, -1, 1};

int dfs(int r, int c) {
    int best = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        int fr = r + 2 * dr[i];
        int fc = c + 2 * dc[i];
        if (fr >= 0 && fr < N && fc >= 0 && fc < M) {
            if (grid[nr][nc] == 2 && grid[fr][fc] == 0) {
                grid[nr][nc] = 0;
                int res = 1 + dfs(fr, fc);
                if (res > best) best = res;
                grid[nr][nc] = 2;
            }
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N >> M && (N != 0 || M != 0)) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if ((r + c) % 2 == 0) {
                    cin >> grid[r][c];
                } else {
                    grid[r][c] = -1;
                }
            }
        }
        int max_cap = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    int res = dfs(r, c);
                    if (res > max_cap) max_cap = res;
                    grid[r][c] = 1;
                }
            }
        }
        cout << max_cap << "\n";
    }
    return 0;
}
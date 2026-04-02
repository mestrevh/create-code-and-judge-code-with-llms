/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

static int M, N;
static int grid[1005][1005];
static int dist[1005][1005][4];
static int dr[] = {0, 1, 0, -1};
static int dc[] = {1, 0, -1, 0};
const int INF = 1e9;

void solve(int r, int c, int dir, int cost) {
    if (cost >= dist[r][c][dir]) return;
    dist[r][c][dir] = cost;
    
    if (r == M - 1 && c == N - 1) return;

    int nr = r + dr[dir];
    int nc = c + dc[dir];
    if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1) {
        solve(nr, nc, dir, cost);
    }

    for (int i = 0; i < 4; i++) {
        if (i == dir) continue;
        nr = r + dr[i];
        nc = c + dc[i];
        if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1) {
            solve(nr, nc, i, cost + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M >> N)) return 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    if (M == 1 && N == 1) {
        if (grid[0][0] == 1) {
            cout << "O caminho tem complexidade: 0" << endl;
        } else {
            cout << "Welcome to the Upside Down." << endl;
        }
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        int nr = 0 + dr[i];
        int nc = 0 + dc[i];
        if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1) {
            solve(nr, nc, i, 0);
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        if (dist[M - 1][N - 1][i] < ans) {
            ans = dist[M - 1][N - 1][i];
        }
    }

    if (ans == INF) {
        cout << "Welcome to the Upside Down." << endl;
    } else {
        cout << "O caminho tem complexidade: " << ans << endl;
    }

    return 0;
}
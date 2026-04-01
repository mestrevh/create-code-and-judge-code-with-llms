/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int grid[1005][1005];
int dist[1005][1005][4];
int dr[] = {-1, 1, 0, 0}; // 0: Up, 1: Down, 2: Left, 3: Right
int dc[] = {0, 0, -1, 1};
int min_comp = 1e9;

void solve(int r, int c, int last_dir, int comp) {
    if (comp >= min_comp) return;
    
    if (r == N - 1 && c == M - 1) {
        min_comp = comp;
        return;
    }

    // Attempt to continue in the same direction first to facilitate pruning
    if (last_dir != -1) {
        int nr = r + dr[last_dir];
        int nc = c + dc[last_dir];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == 1) {
            if (comp < dist[nr][nc][last_dir]) {
                dist[nr][nc][last_dir] = comp;
                solve(nr, nc, last_dir, comp);
            }
        }
    }

    // Attempt all other directions
    for (int i = 0; i < 4; ++i) {
        if (i == last_dir) continue;
        
        int next_comp = (last_dir == -1) ? 0 : comp + 1;
        if (next_comp < min_comp) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == 1) {
                if (next_comp < dist[nr][nc][i]) {
                    dist[nr][nc][i] = next_comp;
                    solve(nr, nc, i, next_comp);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            for (int k = 0; k < 4; ++k) {
                dist[i][j][k] = 1e9;
            }
        }
    }

    // Base validation for start and end points
    if (N > 0 && M > 0 && grid[0][0] == 1 && grid[N - 1][M - 1] == 1) {
        // Initial state at 0,0 with no direction yet (-1) and complexity 0
        solve(0, 0, -1, 0);
    }

    if (min_comp == 1e9) {
        cout << "Continuem cavando!" << endl;
    } else {
        cout << "O caminho tem complexidade: " << min_comp << endl;
    }

    return 0;
}
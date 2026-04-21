/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
int H[105][105];
bool visited[105][105];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(int r, int c, int h) {
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 1 && nr <= R && nc >= 1 && nc <= C && !visited[nr][nc] && H[nr][nc] == h) {
            dfs(nr, nc, h);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C)) return 0;

    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            H[i][j] = 0;
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> H[i][j];
        }
    }

    long long faces = 1; // Bottom face (always 1)

    // Top faces (connected components of same-height cells)
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!visited[i][j]) {
                faces++;
                dfs(i, j, H[i][j]);
            }
        }
    }

    // Side faces (Row boundaries - North/South facing walls)
    for (int i = 1; i <= R + 1; i++) {
        // Looking one way (North facing)
        for (int j = 1; j <= C; j++) {
            if (H[i][j] > H[i - 1][j]) {
                bool connected = false;
                if (j > 1 && H[i][j - 1] > H[i - 1][j - 1]) {
                    // Check if the vertical intervals overlap to form a continuous face
                    if (max(H[i - 1][j], H[i - 1][j - 1]) < min(H[i][j], H[i][j - 1])) {
                        connected = true;
                    }
                }
                if (!connected) faces++;
            }
        }
        // Looking the other way (South facing)
        for (int j = 1; j <= C; j++) {
            if (H[i - 1][j] > H[i][j]) {
                bool connected = false;
                if (j > 1 && H[i - 1][j - 1] > H[i][j - 1]) {
                    if (max(H[i][j], H[i][j - 1]) < min(H[i - 1][j], H[i - 1][j - 1])) {
                        connected = true;
                    }
                }
                if (!connected) faces++;
            }
        }
    }

    // Side faces (Column boundaries - West/East facing walls)
    for (int j = 1; j <= C + 1; j++) {
        // Looking one way (West facing)
        for (int i = 1; i <= R; i++) {
            if (H[i][j] > H[i][j - 1]) {
                bool connected = false;
                if (i > 1 && H[i - 1][j] > H[i - 1][j - 1]) {
                    if (max(H[i][j - 1], H[i - 1][j - 1]) < min(H[i][j], H[i - 1][j])) {
                        connected = true;
                    }
                }
                if (!connected) faces++;
            }
        }
        // Looking the other way (East facing)
        for (int i = 1; i <= R; i++) {
            if (H[i][j - 1] > H[i][j]) {
                bool connected = false;
                if (i > 1 && H[i - 1][j - 1] > H[i - 1][j]) {
                    if (max(H[i][j], H[i - 1][j]) < min(H[i][j - 1], H[i - 1][j - 1])) {
                        connected = true;
                    }
                }
                if (!connected) faces++;
            }
        }
    }

    cout << faces << endl;

    return 0;
}
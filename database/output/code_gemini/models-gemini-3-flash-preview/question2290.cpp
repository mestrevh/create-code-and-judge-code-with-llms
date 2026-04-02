/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<vector<char>> grid(M, vector<char>(M));
    int r = -1, c = -1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (!(cin >> grid[i][j])) break;
            if (grid[i][j] == '#') {
                r = i;
                c = j;
            }
        }
    }

    bool gameOver = false;
    for (int i = 0; i < N; i++) {
        char move;
        if (!(cin >> move)) break;
        if (gameOver) continue;

        int nr = r, nc = c;
        if (move == 'D') nc = (c + 1) % M;
        else if (move == 'E') nc = (c - 1 + M) % M;
        else if (move == 'C') nr = (r - 1 + M) % M;
        else if (move == 'B') nr = (r + 1) % M;

        if (grid[nr][nc] == '@') {
            gameOver = true;
        } else {
            // Snake of length 1, moves out of current cell (r, c)
            // If the map size is 1x1, nr and nc will be the same as r and c.
            // In that case, we set it to '*' and then back to '#'.
            grid[r][c] = '*';
            grid[nr][nc] = '#';
            r = nr;
            c = nc;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }

    if (gameOver) {
        cout << "Game over." << endl;
    }

    return 0;
}
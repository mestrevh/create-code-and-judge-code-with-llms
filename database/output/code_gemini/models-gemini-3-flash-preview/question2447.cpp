/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int grid[6][7];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            grid[i][j] = 0;
        }
    }

    bool gameEnded = false;
    for (int m = 0; m < 42; ++m) {
        int col;
        if (!(cin >> col)) break;
        if (gameEnded) continue;

        int player = (m % 2) + 1;
        int row_placed = -1;
        
        // Piece falls to the deepest empty row in the column
        for (int r = 5; r >= 0; --r) {
            if (grid[r][col] == 0) {
                grid[r][col] = player;
                row_placed = r;
                break;
            }
        }

        if (row_placed != -1) {
            int r = row_placed;
            int c = col;
            int p = player;
            bool win = false;

            // Vertical win check
            int cnt = 0;
            for (int i = 0; i < 6; ++i) {
                if (grid[i][c] == p) {
                    if (++cnt >= 4) win = true;
                } else {
                    cnt = 0;
                }
            }

            // Horizontal win check
            if (!win) {
                cnt = 0;
                for (int j = 0; j < 7; ++j) {
                    if (grid[r][j] == p) {
                        if (++cnt >= 4) win = true;
                    } else {
                        cnt = 0;
                    }
                }
            }

            // Diagonal (\) win check
            if (!win) {
                cnt = 0;
                for (int i = -6; i <= 6; ++i) {
                    int nr = r + i;
                    int nc = c + i;
                    if (nr >= 0 && nr < 6 && nc >= 0 && nc < 7) {
                        if (grid[nr][nc] == p) {
                            if (++cnt >= 4) win = true;
                        } else {
                            cnt = 0;
                        }
                    }
                }
            }

            // Diagonal (/) win check
            if (!win) {
                cnt = 0;
                for (int i = -6; i <= 6; ++i) {
                    int nr = r - i;
                    int nc = c + i;
                    if (nr >= 0 && nr < 6 && nc >= 0 && nc < 7) {
                        if (grid[nr][nc] == p) {
                            if (++cnt >= 4) win = true;
                        } else {
                            cnt = 0;
                        }
                    }
                }
            }

            if (win) {
                cout << "Jogador " << p << " Venceu!" << endl;
                cout << "Estado Final do Jogo:" << endl;
                for (int i = 0; i < 6; ++i) {
                    cout << "| ";
                    for (int j = 0; j < 7; ++j) {
                        cout << grid[i][j] << (j == 6 ? "" : " ");
                    }
                    cout << " |" << endl;
                }
                gameEnded = true;
            }
        }
    }

    return 0;
}
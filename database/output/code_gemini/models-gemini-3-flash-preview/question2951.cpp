/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

char board[8][8];

bool isAttacked(int r, int c) {
    // Knight 'c' (Cavalo)
    int drC[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dcC[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for (int i = 0; i < 8; i++) {
        int nr = r + drC[i], nc = c + dcC[i];
        if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
            if (board[nr][nc] == 'c') return true;
        }
    }

    // Rook 't' (Torre) and Queen 'q'
    int drT[] = {0, 0, 1, -1};
    int dcT[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        for (int d = 1; d < 8; d++) {
            int nr = r + drT[i] * d, nc = c + dcT[i] * d;
            if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) break;
            if (board[nr][nc] == 't' || board[nr][nc] == 'q') return true;
            if (board[nr][nc] != '-') break;
        }
    }

    // Bishop 'b' (Bispo) and Queen 'q'
    int drB[] = {1, 1, -1, -1};
    int dcB[] = {1, -1, 1, -1};
    for (int i = 0; i < 4; i++) {
        for (int d = 1; d < 8; d++) {
            int nr = r + drB[i] * d, nc = c + dcB[i] * d;
            if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) break;
            if (board[nr][nc] == 'b' || board[nr][nc] == 'q') return true;
            if (board[nr][nc] != '-') break;
        }
    }

    // Black Pawn 'p' (Peão)
    // Black pawns move from row 0 to row 7.
    // A black pawn 'p' at (r-1, c-1) or (r-1, c+1) attacks white king at (r,c).
    if (r - 1 >= 0) {
        if (c - 1 >= 0 && board[r - 1][c - 1] == 'p') return true;
        if (c + 1 < 8 && board[r - 1][c + 1] == 'p') return true;
    }

    // Black King 'k' (Rei)
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                if (board[nr][nc] == 'k') return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rk = -1, ck = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (!(cin >> board[i][j])) break;
            if (board[i][j] == 'K') {
                rk = i;
                ck = j;
            }
        }
    }

    if (rk == -1) return 0;

    if (!isAttacked(rk, ck)) {
        cout << "NAO XEQUE" << endl;
    } else {
        bool canEscape = false;
        // Check 8 adjacent squares for the white king
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int nr = rk + dr, nc = ck + dc;
                if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                    char target = board[nr][nc];
                    // King cannot move to a square occupied by its own pieces (Uppercase)
                    if (target == 'P' || target == 'T' || target == 'C' || 
                        target == 'B' || target == 'Q' || target == 'K') continue;

                    // Temporary move simulation
                    char backup_target = board[nr][nc];
                    board[rk][ck] = '-';
                    board[nr][nc] = 'K';

                    if (!isAttacked(nr, nc)) {
                        canEscape = true;
                    }

                    // Undo move
                    board[nr][nc] = backup_target;
                    board[rk][ck] = 'K';

                    if (canEscape) break;
                }
            }
            if (canEscape) break;
        }

        if (canEscape) {
            cout << "XEQUE" << endl;
        } else {
            cout << "XEQUE-MATE" << endl;
        }
    }

    return 0;
}
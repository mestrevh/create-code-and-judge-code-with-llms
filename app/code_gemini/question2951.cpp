/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

char board[8][8];

bool is_valid(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

bool is_attacked(int r_target, int c_target) {
    // Pawns
    if (is_valid(r_target - 1, c_target - 1) && board[r_target - 1][c_target - 1] == 'p') return true;
    if (is_valid(r_target - 1, c_target + 1) && board[r_target - 1][c_target + 1] == 'p') return true;

    // Knights
    int knight_dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int knight_dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for (int i = 0; i < 8; ++i) {
        int r = r_target + knight_dr[i];
        int c = c_target + knight_dc[i];
        if (is_valid(r, c) && board[r][c] == 'c') return true;
    }

    // Rooks and Queens (straight lines)
    int straight_dr[] = {-1, 1, 0, 0};
    int straight_dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int r = r_target + straight_dr[i];
        int c = c_target + straight_dc[i];
        while (is_valid(r, c)) {
            if (board[r][c] != '-') {
                if (board[r][c] == 't' || board[r][c] == 'q') return true;
                break;
            }
            r += straight_dr[i];
            c += straight_dc[i];
        }
    }

    // Bishops and Queens (diagonal lines)
    int diag_dr[] = {-1, -1, 1, 1};
    int diag_dc[] = {-1, 1, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int r = r_target + diag_dr[i];
        int c = c_target + diag_dc[i];
        while (is_valid(r, c)) {
            if (board[r][c] != '-') {
                if (board[r][c] == 'b' || board[r][c] == 'q') return true;
                break;
            }
            r += diag_dr[i];
            c += diag_dc[i];
        }
    }
    
    // King
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = r_target + dr;
            int c = c_target + dc;
            if (is_valid(r, c) && board[r][c] == 'k') return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int king_r = -1, king_c = -1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'K') {
                king_r = i;
                king_c = j;
            }
        }
    }

    if (!is_attacked(king_r, king_c)) {
        cout << "NAO XEQUE" << endl;
        return 0;
    }

    bool can_escape = false;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;

            int new_r = king_r + dr;
            int new_c = king_c + dc;

            if (is_valid(new_r, new_c)) {
                if (!isupper(board[new_r][new_c])) {
                    if (!is_attacked(new_r, new_c)) {
                        can_escape = true;
                        break;
                    }
                }
            }
        }
        if (can_escape) break;
    }

    if (can_escape) {
        cout << "XEQUE" << endl;
    } else {
        cout << "XEQUE-MATE" << endl;
    }

    return 0;
}

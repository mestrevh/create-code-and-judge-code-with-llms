/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

char board[8][8];
int king_r, king_c;

bool check_pawn(int r, int c) {
    if (r + 1 == king_r && (c + 1 == king_c || c - 1 == king_c)) {
        return true;
    }
    return false;
}

bool check_knight(int r, int c) {
    int dr = abs(r - king_r);
    int dc = abs(c - king_c);
    return (dr == 1 && dc == 2) || (dr == 2 && dc == 1);
}

bool check_straight(int r, int c) {
    if (r != king_r && c != king_c) {
        return false;
    }
    if (r == king_r) {
        int start_c = min(c, king_c);
        int end_c = max(c, king_c);
        for (int i = start_c + 1; i < end_c; ++i) {
            if (board[r][i] != '-') {
                return false;
            }
        }
        return true;
    }
    if (c == king_c) {
        int start_r = min(r, king_r);
        int end_r = max(r, king_r);
        for (int i = start_r + 1; i < end_r; ++i) {
            if (board[i][c] != '-') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool check_diagonal(int r, int c) {
    if (abs(r - king_r) != abs(c - king_c)) {
        return false;
    }
    int dr = (king_r > r) ? 1 : -1;
    int dc = (king_c > c) ? 1 : -1;
    int cr = r + dr;
    int cc = c + dc;
    while (cr != king_r) {
        if (board[cr][cc] != '-') {
            return false;
        }
        cr += dr;
        cc += dc;
    }
    return true;
}

bool check_king(int r, int c) {
    return abs(r - king_r) <= 1 && abs(c - king_c) <= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'K') {
                king_r = i;
                king_c = j;
            }
        }
    }

    bool in_check = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char piece = board[i][j];
            if (piece >= 'a' && piece <= 'z') {
                switch (piece) {
                    case 'p':
                        if (check_pawn(i, j)) in_check = true;
                        break;
                    case 'c':
                        if (check_knight(i, j)) in_check = true;
                        break;
                    case 't':
                        if (check_straight(i, j)) in_check = true;
                        break;
                    case 'b':
                        if (check_diagonal(i, j)) in_check = true;
                        break;
                    case 'q':
                        if (check_straight(i, j) || check_diagonal(i, j)) in_check = true;
                        break;
                    case 'k':
                        if (check_king(i, j)) in_check = true;
                        break;
                }
            }
            if (in_check) break;
        }
        if (in_check) break;
    }

    if (in_check) {
        cout << "XEQUE\n";
    } else {
        cout << "NAO XEQUE\n";
    }

    return 0;
}

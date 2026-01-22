/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findKing(const vector<vector<char>>& board) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] == 'K')
                return {i, j};
    return {-1, -1}; // shouldn`t happen
}

bool inBounds(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool isUnderAttack(const vector<vector<char>>& board, int kingX, int kingY) {
    const int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    const int pawnMoves[2][2] = {{-1, -1}, {-1, 1}};
    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // Vertical and horizontal for Rooks & Queens
    const int diagDirections[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // Diagonal for Bishops & Queens

    // Check for knights
    for (const auto& move : knightMoves) {
        int x = kingX + move[0], y = kingY + move[1];
        if (inBounds(x, y) && board[x][y] == 'c') return true;
    }

    // Check for pawns
    for (const auto& move : pawnMoves) {
        int x = kingX + move[0], y = kingY + move[1];
        if (inBounds(x, y) && board[x][y] == 'p') return true;
    }

    // Check for rooks and queens in vertical and horizontal directions
    for (const auto& dir : directions) {
        int x = kingX, y = kingY;
        while (true) {
            x += dir[0];
            y += dir[1];
            if (!inBounds(x, y)) break;
            if (board[x][y] != '-') break; // Blocked
            if (board[x][y] == 't' || board[x][y] == 'q') return true;
        }
    }

    // Check for bishops and queens in diagonal directions
    for (const auto& dir : diagDirections) {
        int x = kingX, y = kingY;
        while (true) {
            x += dir[0];
            y += dir[1];
            if (!inBounds(x, y)) break;
            if (board[x][y] != '-') break; // Blocked
            if (board[x][y] == 'b' || board[x][y] == 'q') return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];

    auto [kingX, kingY] = findKing(board);
    if (isUnderAttack(board, kingX, kingY)) {
        cout << "XEQUE" << endl;
    } else {
        cout << "NAO XEQUE" << endl;
    }
    return 0;
}

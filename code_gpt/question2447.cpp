/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

bool checkWin(vector<vector<int>>& board, int player) {
    // Check horizontal, vertical and diagonal
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == player) {
                // Horizontal
                if (c + 3 < COLS && board[r][c + 1] == player && board[r][c + 2] == player && board[r][c + 3] == player)
                    return true;
                // Vertical
                if (r + 3 < ROWS && board[r + 1][c] == player && board[r + 2][c] == player && board[r + 3][c] == player)
                    return true;
                // Diagonal \
                if (r + 3 < ROWS && c + 3 < COLS && board[r + 1][c + 1] == player && board[r + 2][c + 2] == player && board[r + 3][c + 3] == player)
                    return true;
                // Diagonal /
                if (r - 3 >= 0 && c + 3 < COLS && board[r - 1][c + 1] == player && board[r - 2][c + 2] == player && board[r - 3][c + 3] == player)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board(ROWS, vector<int>(COLS, 0));
    vector<int> moves(42);
    for (int& move : moves) {
        cin >> move;
    }
    
    for (int i = 0; i < moves.size(); i++) {
        int player = (i % 2) + 1;  // Player 1 or 2
        int col = moves[i];
        
        for (int r = ROWS - 1; r >= 0; r--) {
            if (board[r][col] == 0) {
                board[r][col] = player;
                if (checkWin(board, player)) {
                    cout << "Jogador " << player << " Venceu!" << endl;
                } else if (i == 41) {
                    cout << "Empate!" << endl;
                }
                break;
            }
        }
    }

    cout << "Estado Final do Jogo:" << endl;
    for (const auto& row : board) {
        cout << "| ";
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << "|" << endl;
    }
    return 0;
}

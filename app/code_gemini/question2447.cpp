/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

bool checkWin(const std::vector<std::vector<int>>& board, int r, int c) {
    int player = board[r][c];
    if (player == 0) {
        return false;
    }

    // Directions: Horizontal, Vertical, Diagonal down-right, Diagonal up-right
    int dr[] = {0, 1, 1, 1};
    int dc[] = {1, 0, 1, -1};

    for (int i = 0; i < 4; ++i) {
        int count = 1;
        
        // Check in one direction
        for (int k = 1; k < 4; ++k) {
            int nr = r + k * dr[i];
            int nc = c + k * dc[i];
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc] == player) {
                count++;
            } else {
                break;
            }
        }

        // Check in the opposite direction
        for (int k = 1; k < 4; ++k) {
            int nr = r - k * dr[i];
            int nc = c - k * dc[i];
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc] == player) {
                count++;
            } else {
                break;
            }
        }

        if (count >= 4) {
            return true;
        }
    }

    return false;
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        std::cout << "|";
        for (int j = 0; j < COLS; ++j) {
            std::cout << " " << board[i][j];
        }
        std::cout << " |" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> board(ROWS, std::vector<int>(COLS, 0));
    int winner = 0;
    bool game_over = false;

    for (int i = 0; i < ROWS * COLS; ++i) {
        int player = (i % 2) + 1;
        int col;
        std::cin >> col;

        if (game_over) {
            continue;
        }

        int row = -1;
        for (int r = ROWS - 1; r >= 0; --r) {
            if (board[r][col] == 0) {
                row = r;
                break;
            }
        }

        if (row != -1) {
            board[row][col] = player;
            if (checkWin(board, row, col)) {
                winner = player;
                game_over = true;
            }
        }
    }

    std::cout << "Jogador " << winner << " Venceu!" << std::endl;
    std::cout << "Estado Final do Jogo:" << std::endl;
    printBoard(board);

    return 0;
}

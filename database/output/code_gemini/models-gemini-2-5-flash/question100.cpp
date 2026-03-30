/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

// Function to check if a player has won
bool check_win(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    // Standard competitive programming I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_games;
    std::cin >> num_games;

    while (num_games--) {
        std::vector<std::vector<char>> board(3, std::vector<char>(3));
        int countX = 0;
        int countO = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cin >> board[i][j];
                if (board[i][j] == 'X') {
                    countX++;
                } else if (board[i][j] == 'O') {
                    countO++;
                }
            }
        }

        bool x_wins = check_win(board, 'X');
        bool o_wins = check_win(board, 'O');

        // Rule 1: Basic count check (X always starts)
        // O cannot have more moves than X (countO > countX).
        // X cannot have more than one extra move than O (countX > countO + 1).
        if (countO > countX || countX > countO + 1) {
            std::cout << "ILEGAL\n";
            continue;
        }

        // Rule 2: Check for simultaneous wins (illegal)
        if (x_wins && o_wins) {
            std::cout << "ILEGAL\n";
            continue;
        }

        // Rule 3: Check if X won
        if (x_wins) {
            // If X won, X must have made the last move.
            // This means countX must be exactly countO + 1.
            // If countX == countO, it implies O played after X won, which is illegal.
            if (countX == countO) {
                std::cout << "ILEGAL\n";
            } else { // countX == countO + 1 is the only valid state if X won
                std::cout << "X_VENCEU\n";
            }
            continue;
        }

        // Rule 4: Check if O won
        if (o_wins) {
            // If O won, O must have made the last move.
            // This means countX must be exactly countO.
            // If countX == countO + 1, it implies X played after O won, which is illegal.
            if (countX == countO + 1) {
                std::cout << "ILEGAL\n";
            } else { // countX == countO is the only valid state if O won
                std::cout << "O_VENCEU\n";
            }
            continue;
        }

        // Rule 5: If no one has won and no illegal conditions found above, the game is ongoing.
        // This covers partially filled boards and full boards that result in a tie.
        // The problem states: "em caso de empate considere que o jogo está em andamento".
        std::cout << "EM_ANDAMENTO\n";
    }

    return 0;
}
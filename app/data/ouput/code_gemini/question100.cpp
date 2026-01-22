/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void solve() {
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

    bool xWins = checkWin(board, 'X');
    bool oWins = checkWin(board, 'O');

    if (countX < countO || countX > countO + 1) {
        std::cout << "ILEGAL" << std::endl;
        return;
    }

    if (xWins && oWins) {
        std::cout << "ILEGAL" << std::endl;
        return;
    }
    
    if (xWins && countX == countO) {
        std::cout << "ILEGAL" << std::endl;
        return;
    }
    
    if (oWins && countX > countO) {
        std::cout << "ILEGAL" << std::endl;
        return;
    }
    
    if (xWins) {
        std::cout << "X_VENCEU" << std::endl;
    } else if (oWins) {
        std::cout << "O_VENCEU" << std::endl;
    } else {
        std::cout << "EM_ANDAMENTO" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkWin(const vector<string>& board, char player) {
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

int main() {
    int games;
    cin >> games;
    cin.ignore();
    
    while (games--) {
        vector<string> board(3);
        int countX = 0, countO = 0;
        
        for (int i = 0; i < 3; ++i) {
            getline(cin, board[i]);
            for (char c : board[i]) {
                if (c == 'X') countX++;
                else if (c == 'O') countO++;
            }
        }
        
        bool xWins = checkWin(board, 'X');
        bool oWins = checkWin(board, 'O');
        
        if (countO > countX || countX > countO + 1) {
            cout << "ILEGAL" << endl;
        } else if (xWins && oWins) {
            cout << "ILEGAL" << endl;
        } else if (xWins) {
            cout << "X_VENCEU" << endl;
        } else if (oWins) {
            cout << "O_VENCEU" << endl;
        } else {
            cout << "EM_ANDAMENTO" << endl;
        }
    }
    
    return 0;
}

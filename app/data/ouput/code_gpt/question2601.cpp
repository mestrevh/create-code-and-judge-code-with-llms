/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player, string& location) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            location = "linha " + to_string(i + 1);
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            location = "coluna " + to_string(i + 1);
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        location = "diagonal principal";
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        location = "diagonal secundaria";
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '*'));
    int N;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }
    
    cin >> N;
    string location;
    bool won = false;

    for (int i = 0; i < N; ++i) {
        char symbol;
        int x, y;
        cin >> symbol >> x >> y;
        
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "O Dark Souls afetou sua cabeça? Jogue dentro das demarcações do jogo." << endl;
            continue;
        }

        if (board[x][y] != '*') {
            if (symbol == 'X') {
                cout << "Eduardo não trapacei ou então vamos voltar a jogar Dark Souls." << endl;
            } else {
                cout << "Leonardo não trapacei ou então vamos voltar a jogar Dark Souls." << endl;
            }
            continue;
        }

        board[x][y] = symbol;
        if (symbol == 'X') {
            cout << "Eduardo efetuou sua jogada com sucesso." << endl;
            if (checkWin(board, 'X', location)) {
                won = true;
                cout << "Eduardo ganhou o jogo na " << location << "." << endl;
            }
        } else {
            cout << "Leonardo efetuou sua jogada com sucesso." << endl;
            if (checkWin(board, 'O', location)) {
                won = true;
                cout << "Leonardo ganhou o jogo na " << location << "." << endl;
            }
        }
        
        if (won) break;
    }
    
    if (!won) {
        cout << "Nem no jogo da velha conseguimos ganhar algo, vamos voltar para o Dark Souls." << endl;
    }

    printBoard(board);
    return 0;
}

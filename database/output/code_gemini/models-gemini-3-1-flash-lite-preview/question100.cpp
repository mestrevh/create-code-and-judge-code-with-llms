/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_win(const vector<vector<char>>& board, char p) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

void solve() {
    vector<vector<char>> board(3, vector<char>(3));
    int x_count = 0, o_count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'X') x_count++;
            else if (board[i][j] == 'O') o_count++;
        }
    }

    bool x_won = check_win(board, 'X');
    bool o_won = check_win(board, 'O');

    if (!(x_count == o_count || x_count == o_count + 1) || (x_won && o_won) || (x_won && x_count != o_count + 1) || (o_won && x_count != o_count)) {
        cout << "ILEGAL" << endl;
        return;
    }

    if (x_won) cout << "X_VENCEU" << endl;
    else if (o_won) cout << "O_VENCEU" << endl;
    else cout << "EM_ANDAMENTO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
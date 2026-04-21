/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool check(char p, char b[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p) return true;
        if (b[0][i] == p && b[1][i] == p && b[2][i] == p) return true;
    }
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p) return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        char board[3][3];
        int countX = 0, countO = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(cin >> board[i][j])) break;
                if (board[i][j] == 'X') countX++;
                else if (board[i][j] == 'O') countO++;
            }
        }

        bool winX = check('X', board);
        bool winO = check('O', board);

        if (countX < countO || countX > countO + 1) {
            cout << "ILEGAL" << "\n";
        } else if (winX && winO) {
            cout << "ILEGAL" << "\n";
        } else if (winX && countX != countO + 1) {
            cout << "ILEGAL" << "\n";
        } else if (winO && countX != countO) {
            cout << "ILEGAL" << "\n";
        } else if (winX) {
            cout << "X_VENCEU" << "\n";
        } else if (winO) {
            cout << "O_VENCEU" << "\n";
        } else {
            cout << "EM_ANDAMENTO" << "\n";
        }
    }
    return 0;
}
/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int empty_row, empty_col;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'x') {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
    }

    char move;
    while (cin >> move) {
        int next_row = empty_row;
        int next_col = empty_col;

        if (move == 'U') {
            next_row--;
        } else if (move == 'D') {
            next_row++;
        } else if (move == 'L') {
            next_col--;
        } else if (move == 'R') {
            next_col++;
        }

        if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
            swap(board[empty_row][empty_col], board[next_row][next_col]);
            empty_row = next_row;
            empty_col = next_col;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << board[i] << endl;
    }

    return 0;
}

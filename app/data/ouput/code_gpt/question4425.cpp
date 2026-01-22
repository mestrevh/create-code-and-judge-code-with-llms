/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> board(N);
    int empty_x, empty_y;

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 'x') {
                empty_x = i;
                empty_y = j;
            }
        }
    }

    string moves;
    cin.ignore();
    while (getline(cin, moves)) {
        for (char move : moves) {
            int new_x = empty_x, new_y = empty_y;
            if (move == 'L') new_y--;
            else if (move == 'R') new_y++;
            else if (move == 'U') new_x--;
            else if (move == 'D') new_x++;

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
                swap(board[empty_x][empty_y], board[new_x][new_y]);
                empty_x = new_x;
                empty_y = new_y;
            }
        }
    }

    for (const string& row : board) {
        cout << row << endl;
    }

    return 0;
}

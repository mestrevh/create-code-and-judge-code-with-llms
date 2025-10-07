/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& board, int l, int c) {
    vector<vector<int>> temp(l, vector<int>(c));
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            temp[j][l - 1 - i] = board[i][j];
    board = temp;
}

int main() {
    int l, c, n;
    cin >> l >> c >> n;
    vector<vector<int>> board(l, vector<int>(c));

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            cin >> board[i][j];

    n = ((n % 4) + 4) % 4; // Normalize rotation count
    for (int i = 0; i < n; ++i)
        rotate(board, l, c);

    for (const auto& row : board) {
        for (int j = 0; j < c; ++j) {
            cout << row[j] << (j < c - 1 ? " " : "");
        }
        cout << endl;
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (board[row][x] == num || board[x][col] == num || board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num)
            return false;
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> board(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < 9; j++) {
                board[i][j] = line[j] - '0';
            }
        }
        solveSudoku(board);
        for (const auto& row : board) {
            for (int num : row)
                cout << num;
            cout << endl;
        }
    }
    return 0;
}

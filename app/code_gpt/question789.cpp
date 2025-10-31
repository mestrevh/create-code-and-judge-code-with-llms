/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        unordered_set<int> rowSet, colSet, boxSet;
        for (int j = 0; j < 9; j++) {
            // Verifica linha
            if (board[i][j] != 0) {
                if (rowSet.count(board[i][j])) return false;
                rowSet.insert(board[i][j]);
            }
            // Verifica coluna
            if (board[j][i] != 0) {
                if (colSet.count(board[j][i])) return false;
                colSet.insert(board[j][i]);
            }
            // Verifica caixa 3x3
            int rowIndex = 3 * (i / 3), colIndex = 3 * (i % 3);
            int num = board[rowIndex + j / 3][colIndex + j % 3];
            if (num != 0) {
                if (boxSet.count(num)) return false;
                boxSet.insert(num);
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        vector<vector<int>> board(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> board[i][j];

        cout << "Instancia " << k << endl;
        cout << (isValidSudoku(board) ? "SIM" : "NAO") << endl << endl;
    }

    return 0;
}

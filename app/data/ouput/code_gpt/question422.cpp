/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int board[8][8] = {0};
vector<vector<int>> solutions;
int queen_row;

bool is_safe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (board[i][j]) return false;
    return true;
}

void solve(int col) {
    if (col == 8) {
        vector<int> solution;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j]) solution.push_back(i + 1);
            }
        }
        solutions.push_back(solution);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (is_safe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n" << endl;

    while (test_cases--) {
        cin >> queen_row;
        int queen_col = 1;
        queen_row--;  // To make it zero-indexed
        board[queen_row][queen_col - 1] = 1;
        solve(0);
        int count = 1;
        for (const auto& sol : solutions) {
            cout << setw(2) << count++ << "      ";
            for (int i : sol) {
                cout << i << " ";
            }
            cout << endl;
        }
        if (test_cases) cout << endl; // Blank line between test cases
        solutions.clear();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = 0; // Reset the board
            }
        }
    }
    return 0;
}

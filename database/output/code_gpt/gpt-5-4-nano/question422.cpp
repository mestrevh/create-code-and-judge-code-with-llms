/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct CaseSolver {
    int fixedR, fixedC;
    vector<int> fixedRowOfCol; 
    vector<int> sol;
    vector<vector<int>> solutions;

    bool canPlace(int col, int row, const vector<int>& rowsUsed, const vector<int>& diag1, const vector<int>& diag2) {
        if (rowsUsed[row]) return false;
        int d1 = row - col + 7;
        int d2 = row + col;
        if (diag1[d1]) return false;
        if (diag2[d2]) return false;
        return true;
    }

    void backtrack(int col, vector<int>& rowsUsed, vector<int>& diag1, vector<int>& diag2, vector<int>& posRow) {
        if (col == 9) {
            solutions.push_back(posRow);
            return;
        }
        if (col == fixedC) {
            int row = fixedR;
            if (canPlace(col, row, rowsUsed, diag1, diag2)) {
                int d1 = row - col + 7;
                int d2 = row + col;
                rowsUsed[row] = 1;
                diag1[d1] = 1;
                diag2[d2] = 1;
                posRow[col] = row;
                backtrack(col + 1, rowsUsed, diag1, diag2, posRow);
                posRow[col] = 0;
                rowsUsed[row] = 0;
                diag1[d1] = 0;
                diag2[d2] = 0;
            }
            return;
        }
        for (int row = 1; row <= 8; row++) {
            if (!canPlace(col, row, rowsUsed, diag1, diag2)) continue;
            int d1 = row - col + 7;
            int d2 = row + col;
            rowsUsed[row] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;
            posRow[col] = row;
            backtrack(col + 1, rowsUsed, diag1, diag2, posRow);
            posRow[col] = 0;
            rowsUsed[row] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }

    vector<vector<int>> solve(int r, int c) {
        fixedR = r; fixedC = c;
        solutions.clear();
        vector<int> rowsUsed(9, 0);
        vector<int> diag1(16, 0);
        vector<int> diag2(17, 0);
        vector<int> posRow(9, 0);

        int row = fixedR;
        int col = fixedC;
        rowsUsed[row] = 1;
        diag1[row - col + 7] = 1;
        diag2[row + col] = 1;
        posRow[col] = row;

        backtrack(1, rowsUsed, diag1, diag2, posRow);

        return solutions;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string dummy;
    getline(cin, dummy);

    for (int tc = 0; tc < T; tc++) {
        int r, c;
        cin >> r >> c;
        CaseSolver solver;
        auto sols = solver.solve(r, c);

        int n = (int)sols.size();

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        bool leftAlign = (n >= 10);
        for (int i = 0; i < n; i++) {
            int k = i + 1;
            if (leftAlign) {
                cout << setw(2) << k << "      ";
            } else {
                cout << " " << k << "      ";
            }
            auto &p = sols[i];
            for (int col = 1; col <= 8; col++) {
                cout << p[col] << (col == 8 ? '\n' : ' ');
            }
        }

        if (tc != T - 1) cout << "\n";
    }

    return 0;
}
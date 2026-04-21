/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool solve() {
    int grid[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 9; ++i) {
        int rowMask = 0;
        int colMask = 0;
        for (int j = 0; j < 9; ++j) {
            int rVal = grid[i][j];
            if (rVal < 1 || rVal > 9 || (rowMask & (1 << rVal))) return false;
            rowMask |= (1 << rVal);

            int cVal = grid[j][i];
            if (cVal < 1 || cVal > 9 || (colMask & (1 << cVal))) return false;
            colMask |= (1 << cVal);
        }
    }

    for (int block = 0; block < 9; ++block) {
        int mask = 0;
        int rStart = (block / 3) * 3;
        int cStart = (block % 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[rStart + i][cStart + j];
                if (val < 1 || val > 9 || (mask & (1 << val))) return false;
                mask |= (1 << val);
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int k = 1; k <= n; ++k) {
        bool valid = solve();
        cout << "Instancia " << k << "\n";
        if (valid) cout << "SIM\n\n";
        else cout << "NAO\n\n";
    }

    return 0;
}
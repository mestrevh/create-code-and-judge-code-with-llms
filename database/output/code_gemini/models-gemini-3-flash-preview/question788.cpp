/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int grid[9][9];
int rowMask[9], colMask[9], boxMask[9];

bool solve() {
    int r = -1, c = -1, minOps = 10;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == 0) {
                int b = (i / 3) * 3 + (j / 3);
                int possible = ~(rowMask[i] | colMask[j] | boxMask[b]) & 0x3FE;
                int cnt = __builtin_popcount(possible);
                if (cnt < minOps) {
                    minOps = cnt;
                    r = i;
                    c = j;
                    if (minOps == 0) return false;
                }
            }
        }
    }

    if (r == -1) return true;

    int b = (r / 3) * 3 + (c / 3);
    int possible = ~(rowMask[r] | colMask[c] | boxMask[b]) & 0x3FE;
    while (possible) {
        int bit = possible & -possible;
        int val = __builtin_ctz(bit);
        grid[r][c] = val;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;
        if (solve()) return true;
        grid[r][c] = 0;
        rowMask[r] &= ~bit;
        colMask[c] &= ~bit;
        boxMask[b] &= ~bit;
        possible &= ~bit;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        for (int i = 0; i < 9; ++i) {
            rowMask[i] = colMask[i] = boxMask[i] = 0;
        }
        for (int i = 0; i < 9; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < 9; ++j) {
                grid[i][j] = line[j] - '0';
                if (grid[i][j] != 0) {
                    int bit = 1 << grid[i][j];
                    rowMask[i] |= bit;
                    colMask[j] |= bit;
                    boxMask[(i / 3) * 3 + (j / 3)] |= bit;
                }
            }
        }
        if (solve()) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
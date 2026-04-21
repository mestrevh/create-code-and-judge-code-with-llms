/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline int boxIndex(int r, int c) { return (r/3)*3 + (c/3); }

bool solveSudoku(vector<array<int,9>>& grid, array<int,9>& rowMask, array<int,9>& colMask, array<int,9>& boxMask) {
    int bestR = -1, bestC = -1, bestCount = 10;
    int bestAvailMask = 0;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] != 0) continue;
            int b = boxIndex(r,c);
            int used = rowMask[r] | colMask[c] | boxMask[b];
            int avail = (~used) & 0x1FF;
            int cnt = __builtin_popcount((unsigned)avail);
            if (cnt == 0) return false;
            if (cnt < bestCount) {
                bestCount = cnt;
                bestR = r;
                bestC = c;
                bestAvailMask = avail;
                if (cnt == 1) break;
            }
        }
        if (bestCount == 1) break;
    }

    if (bestR == -1) return true;

    int r = bestR, c = bestC, b = boxIndex(r,c);
    int avail = bestAvailMask;
    while (avail) {
        int bit = avail & -avail;
        int d = __builtin_ctz((unsigned)bit); 
        int val = d + 1;

        grid[r][c] = val;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;

        if (solveSudoku(grid, rowMask, colMask, boxMask)) return true;

        rowMask[r] &= ~bit;
        colMask[c] &= ~bit;
        boxMask[b] &= ~bit;
        grid[r][c] = 0;

        avail ^= bit;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        vector<array<int,9>> grid(9);
        for (int r = 0; r < 9; r++) {
            string s;
            cin >> s;
            for (int c = 0; c < 9; c++) {
                grid[r][c] = s[c] - '0';
            }
        }

        array<int,9> rowMask{}, colMask{}, boxMask{};
        for (int i = 0; i < 9; i++) rowMask[i]=colMask[i]=boxMask[i]=0;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int v = grid[r][c];
                if (v == 0) continue;
                int bit = 1 << (v-1);
                int b = boxIndex(r,c);
                rowMask[r] |= bit;
                colMask[c] |= bit;
                boxMask[b] |= bit;
            }
        }

        solveSudoku(grid, rowMask, colMask, boxMask);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) cout << grid[r][c];
            cout << "\n";
        }
    }
    return 0;
}
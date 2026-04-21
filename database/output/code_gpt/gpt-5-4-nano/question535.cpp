/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;

    for (int tc = 1; tc <= N; tc++) {
        int l, i;
        cin >> l >> i;

        int H = l - 2;
        int W = 2 * (l - 1) + 1;

        vector<string> grid(H + H + 1, string(W, ' '));

        auto starLeftBoundary = [&](int r) -> int {
            return (l - 1) - (r + 1);
        };
        auto starRightBoundary = [&](int r) -> int {
            return (l - 1) + (r + 1);
        };

        for (int r = 0; r <= H - 1; r++) {
            int row = r;
            int L = starLeftBoundary(r);
            int R = starRightBoundary(r);
            grid[row][L] = '*';
            grid[row][R] = '*';
            grid[row][(l - 1)] = (r == 0 ? '*' : '*');
        }

        for (int r = 0; r <= H - 1; r++) {
            int row = H + 1 + r;
            int L = starLeftBoundary(H - 1 - r);
            int R = starRightBoundary(H - 1 - r);
            grid[row][L] = '*';
            grid[row][R] = '*';
            grid[row][(l - 1)] = '*';
        }

        for (int r = 0; r <= H - 1; r++) {
            int row = r;
            int L = starLeftBoundary(r);
            int R = starRightBoundary(r);
            for (int col = L + 1; col <= R - 1; col++) {
                grid[row][col] = ' ';
            }
        }

        for (int r = 0; r <= H - 1; r++) {
            int row = H + 1 + r;
            int L = starLeftBoundary(H - 1 - r);
            int R = starRightBoundary(H - 1 - r);
            for (int col = L + 1; col <= R - 1; col++) {
                grid[row][col] = ' ';
            }
        }

        for (int r = 0; r <= H - 1; r++) {
            int row = r;
            int filledRows = H - 1 - r;
            if (filledRows < i) {
                int L = starLeftBoundary(r);
                int R = starRightBoundary(r);
                for (int col = L + 1; col <= R - 1; col++) grid[row][col] = '.';
            }
            if (filledRows == i) {
                int L = starLeftBoundary(r);
                int R = starRightBoundary(r);
                int mid = l - 1;
                for (int col = L + 1; col <= R - 1; col++) grid[row][col] = ' ';
                grid[row][mid] = '.';
            }
        }

        for (int r = 0; r <= H - 1; r++) {
            int row = H + 1 + r;
            int filledRows = r;
            if (filledRows < i) {
                int idx = H - 1 - r;
                int L = starLeftBoundary(idx);
                int R = starRightBoundary(idx);
                for (int col = L + 1; col <= R - 1; col++) grid[row][col] = '.';
            }
            if (filledRows == i) {
                int idx = H - 1 - r;
                int L = starLeftBoundary(idx);
                int R = starRightBoundary(idx);
                int mid = l - 1;
                for (int col = L + 1; col <= R - 1; col++) grid[row][col] = ' ';
                grid[row][mid] = '.';
            }
        }

        int topRow = 0;
        int bottomRow = H + H;
        for (int col = 0; col < W; col++) {
            if (col < (l - 1) - (H) || col > (l - 1) + (H)) continue;
        }

        for (int c = 0; c < W; c++) {
            int mid = l - 1;
        }

        grid[0][(l - 1)] = '*';
        grid[H][(l - 1)] = '*';

        for (int r = 0; r <= H - 1; r++) {
            int L = starLeftBoundary(r);
            int R = starRightBoundary(r);
            if (r == 0) {
                grid[r][L] = '*';
                grid[r][R] = '*';
            } else {
                grid[r][L] = '*';
                grid[r][R] = '*';
            }
        }

        for (int r = 0; r <= H - 1; r++) {
            int idx = H - 1 - r;
            int L = starLeftBoundary(idx);
            int R = starRightBoundary(idx);
            grid[H + 1 + r][L] = '*';
            grid[H + 1 + r][R] = '*';
        }

        for (int k = 0; k <= H; k++) {
            int rowTop = k;
            int rowBot = H + k + 1;
            int Ltop = (l - 1) - k;
            int Rtop = (l - 1) + k;
            if (rowTop < H + 1) {
                if (k == 0) {
                    grid[rowTop][Ltop] = '*';
                } else {
                    if (grid[rowTop][Ltop] != '*') grid[rowTop][Ltop] = '*';
                    if (grid[rowTop][Rtop] != '*') grid[rowTop][Rtop] = '*';
                }
            }
            if (rowBot < (int)grid.size()) {
                if (k == 0) {
                    grid[rowBot][Ltop] = '*';
                } else {
                    grid[rowBot][Ltop] = '*';
                    grid[rowBot][Rtop] = '*';
                }
            }
        }

        for (int col = 0; col < W; col++) {
            grid[0][col] = ' ';
            grid[bottomRow][col] = ' ';
        }
        for (int col = (l - 1) - H; col <= (l - 1) + H; col++) {
            if (col == (l - 1) - H || col == (l - 1) - H + 1 || col == (l - 1) + H - 1 || col == (l - 1) + H)
                grid[0][col] = '*';
        }

        grid[0][(l - 1) - H] = '*';
        grid[0][(l - 1) - H + 1] = '*';
        for (int col = (l - 1) - H + 2; col <= (l - 1) + H - 2; col += 2) grid[0][col] = '*';
        grid[0][(l - 1) + H - 1] = '*';
        grid[0][(l - 1) + H] = '*';

        int midGapRow = H;
        for (int col = 0; col < W; col++) grid[midGapRow][col] = ' ';
        grid[midGapRow][(l - 1)] = '*';

        for (int col = (l - 1) - H; col <= (l - 1) + H; col++) {
            grid[bottomRow][col] = ' ';
        }
        grid[bottomRow][(l - 1) - H] = '*';
        grid[bottomRow][(l - 1) - H + 1] = '*';
        for (int col = (l - 1) - H + 2; col <= (l - 1) + H - 2; col += 2) grid[bottomRow][col] = '*';
        grid[bottomRow][(l - 1) + H - 1] = '*';
        grid[bottomRow][(l - 1) + H] = '*';

        cout << "Caso " << tc << ":\n";
        for (int r = 0; r < (int)grid.size(); r++) {
            string line = grid[r];
            for (int c = 0; c < (int)line.size(); c++) {
                if (line[c] == '*') {
                    if (c != 0) {}
                }
            }
            int right = (int)line.size() - 1;
            while (right >= 0 && line[right] == ' ') right--;
            if (right < 0) right = 0;
            cout << line.substr(0, right + 1) << "\n";
        }
    }
    return 0;
}
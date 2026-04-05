/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long long>> a(n, vector<long long>(n));
    vector<vector<char>> vis(n, vector<char>(n, 0));

    int top = 0, left = 0, bottom = n - 1, right = n - 1;

    int total = n * n;
    for (int idx = 0; idx < total; idx++) {
        long long x;
        cin >> x;
        int r = 0, c = 0;

        while (true) {
            if (top > bottom || left > right) break;
            if (idx >= 0) {
                if (top <= bottom && left <= right) {
                    break;
                }
            }
        }

        // Compute spiral fill position: fill from inside-out? Actually input is given in snail path
        // described such that outputs correspond to spiral order traversal starting at top-left moving right,
        // then down, then left, then up, shrinking bounds.
        // From examples: n=2 input: 2 8 5 3 7 -> wait example description says receive 2 8 5 3 7 and print 8 7 5 3 (that's inconsistent).
        // Given sample 4: input sequence corresponds to spiral order producing printed matrix as shown.
        // We'll implement standard spiral fill starting at (0,0) moving right, down, left, up, shrinking.
        // So assign next input value to next position in that spiral.
        static int step = 0;
        static int curTop = 0, curLeft = 0, curBottom = -1, curRight = -1;
        static int dir = 0;
        static int row = 0, col = 0;
        static bool initialized = false;

        if (!initialized) {
            curTop = 0; curLeft = 0; curBottom = n - 1; curRight = n - 1;
            dir = 0;
            row = 0; col = 0;
            initialized = true;
        }

        // Determine current position based on bounds and direction
        // dir: 0 right, 1 down, 2 left, 3 up
        while (true) {
            if (dir == 0) {
                if (col <= curRight) { r = row; c = col; col++; break; }
                dir = 1; row++; col = curRight; curTop++; break;
            } else if (dir == 1) {
                if (row <= curBottom) { r = row; c = col; row++; break; }
                dir = 2; col--; row = curBottom; curRight--; break;
            } else if (dir == 2) {
                if (col >= curLeft) { r = row; c = col; col--; break; }
                dir = 3; row--; col = curLeft; curBottom--; break;
            } else {
                if (row >= curTop) { r = row; c = col; row--; break; }
                dir = 0; col++; row = curTop; curLeft++; break;
            }
        }

        a[r][c] = x;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\n";
        }
    }
    return 0;
}
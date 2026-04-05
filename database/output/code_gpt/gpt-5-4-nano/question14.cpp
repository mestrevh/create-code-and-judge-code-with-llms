/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H, N;
    while (true) {
        if (!(cin >> W >> H >> N)) return 0;
        if (W == 0 && H == 0 && N == 0) break;

        vector<vector<int>> diff(H + 3, vector<int>(W + 3, 0));

        for (int i = 0; i < N; i++) {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;
            int xL = min(X1, X2), xR = max(X1, X2);
            int yB = min(Y1, Y2), yT = max(Y1, Y2);

            diff[yB][xL] += 1;
            diff[yB][xR + 1] -= 1;
            diff[yT + 1][xL] -= 1;
            diff[yT + 1][xR + 1] += 1;
        }

        long long occupied = 0;
        for (int y = 1; y <= H; y++) {
            int row = 0;
            for (int x = 1; x <= W; x++) {
                row += diff[y][x];
                diff[y][x] = row + (y > 1 ? diff[y - 1][x] : 0);
                if (diff[y][x] == 0) {
                } else {
                    occupied++;
                }
            }
        }

        long long total = 1LL * W * H;
        long long empty = total - occupied;

        if (empty == 0) {
            cout << "There is no empty spots.\n";
        } else if (empty == 1) {
            cout << "There is one empty spot.\n";
        } else {
            cout << "There are " << empty << " empty spots.\n";
        }
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, P;
    if (!(cin >> H >> W >> P)) return 0;

    int EX, EY, DX, DY;
    cin >> EX >> EY >> DX >> DY;

    vector<string> grid(H + 1, string(W + 1, '.'));

    for (int y = EY; y < DY; y++) {
        for (int x = EX; x < DX; x++) {
            int row = H - y;
            int col = x + 1;
            if (row >= 1 && row <= H && col >= 1 && col <= W) {
                if (P == 1) grid[row - 1][col - 1] = '*';
                else {
                    if (x == EX || x == DX - 1 || y == EY || y == DY - 1) grid[row - 1][col - 1] = '*';
                }
            }
        }
    }

    for (int i = 0; i < H; i++) cout << grid[i] << "\n";
    return 0;
}
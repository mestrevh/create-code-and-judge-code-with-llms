/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, P;
    if (!(cin >> H >> W >> P)) return 0;

    int EX, EY, DX, DY;
    if (!(cin >> EX >> EY >> DX >> DY)) return 0;

    for (int y = H; y >= 0; --y) {
        for (int x = 0; x <= W; ++x) {
            bool in_x = (x >= EX && x <= DX);
            bool in_y = (y >= DY && y <= EY);
            if (in_x && in_y) {
                if (P == 1) {
                    cout << '*';
                } else {
                    if (x == EX || x == DX || y == EY || y == DY) {
                        cout << '*';
                    } else {
                        cout << '.';
                    }
                }
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}
/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int W, H, N;

    while (cin >> W >> H >> N) {
        if (W == 0 && H == 0 && N == 0) break;

        vector<vector<bool>> grid(H + 1, vector<bool>(W + 1, false));

        for (int i = 0; i < N; i++) {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;

            int xStart = min(X1, X2);
            int xEnd = max(X1, X2);
            int yStart = min(Y1, Y2);
            int yEnd = max(Y1, Y2);

            for (int x = xStart; x <= xEnd; x++) {
                for (int y = yStart; y <= yEnd; y++) {
                    grid[y][x] = true;
                }
            }
        }

        int emptyCount = 0;

        for (int y = 1; y <= H; y++) {
            for (int x = 1; x <= W; x++) {
                if (!grid[y][x]) emptyCount++;
            }
        }

        if (emptyCount == 0) {
            cout << "There is no empty spots." << endl;
        } else if (emptyCount == 1) {
            cout << "There is one empty spot." << endl;
        } else {
            cout << "There are " << emptyCount << " empty spots." << endl;
        }
    }

    return 0;
}

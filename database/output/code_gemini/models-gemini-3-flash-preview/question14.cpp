/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H, N;
    while (cin >> W >> H >> N && (W != 0 || H != 0 || N != 0)) {
        vector<vector<bool>> occupied(W + 1, vector<bool>(H + 1, false));

        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            int startX = min(x1, x2);
            int endX = max(x1, x2);
            int startY = min(y1, y2);
            int endY = max(y1, y2);

            for (int x = startX; x <= endX; ++x) {
                if (x < 1 || x > W) continue;
                for (int y = startY; y <= endY; ++y) {
                    if (y < 1 || y > H) continue;
                    occupied[x][y] = true;
                }
            }
        }

        int emptySpots = 0;
        for (int x = 1; x <= W; ++x) {
            for (int y = 1; y <= H; ++y) {
                if (!occupied[x][y]) {
                    emptySpots++;
                }
            }
        }

        if (emptySpots == 0) {
            cout << "There is no empty spots." << "\n";
        } else if (emptySpots == 1) {
            cout << "There is one empty spot." << "\n";
        } else {
            cout << "There are " << emptySpots << " empty spots." << "\n";
        }
    }

    return 0;
}
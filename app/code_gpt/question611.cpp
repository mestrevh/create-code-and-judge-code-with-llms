/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> heights(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> heights[i][j];
        }
    }

    int faces = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int h = heights[i][j];

            faces += 2; // Top and bottom face

            // Check left
            if (j == 0) {
                faces += h; // Exposed face
            } else {
                faces += max(0, h - heights[i][j - 1]);
            }

            // Check right
            if (j == C - 1) {
                faces += h; // Exposed face
            } else {
                faces += max(0, h - heights[i][j + 1]);
            }

            // Check top
            if (i == 0) {
                faces += h; // Exposed face
            } else {
                faces += max(0, h - heights[i - 1][j]);
            }

            // Check bottom
            if (i == R - 1) {
                faces += h; // Exposed face
            } else {
                faces += max(0, h - heights[i + 1][j]);
            }
        }
    }

    cout << faces << endl;
    return 0;
}

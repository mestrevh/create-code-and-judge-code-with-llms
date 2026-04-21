/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> grid(L, vector<int>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int D;
    cin >> D;

    if (L % 2 == 0) {
        // Even L: Row by row, left to right, top to bottom
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                }
            }
        }
    } else {
        // Odd L: Column by column, top to bottom, left to right
        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < L; ++i) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                }
            }
        }
    }

    int alive_count = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) {
                alive_count++;
            }
            cout << grid[i][j] << (j == C - 1 ? "" : " ");
        }
        cout << "\n";
    }
    cout << D << " " << alive_count << endl;

    return 0;
}
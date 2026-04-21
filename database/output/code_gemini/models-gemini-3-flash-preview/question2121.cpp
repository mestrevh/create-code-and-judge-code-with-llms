/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> grid(L, vector<int>(C));
    long long cost = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            string color;
            cin >> color;
            if (color == "verde") {
                grid[i][j] = 1;
            } else if (color == "vermelho") {
                grid[i][j] = 0;
                cost += 3;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    int S;
    if (cin >> S) {
        for (int k = 0; k < S; ++k) {
            int x, y;
            cin >> x >> y;
            if (x >= 1 && x <= L && y >= 1 && y <= C) {
                grid[x - 1][y - 1] = 1;
            }
        }
    }

    long long green_count = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) {
                green_count++;
            }
        }
    }

    long long profit = (green_count * 4) - cost;

    if (profit < 0) {
        cout << "prejuizo" << endl;
    } else {
        cout << profit << endl;
    }

    return 0;
}
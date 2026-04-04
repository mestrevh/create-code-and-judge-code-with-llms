/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

using namespace std;

static bool grid[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        memset(grid, 0, sizeof(grid));
        for (int k = 0; k < n; ++k) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            
            int x1 = a, y1 = b, x2 = c, y2 = d;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            
            if (x1 < 0) x1 = 0;
            if (y1 < 0) y1 = 0;
            if (x2 > 500) x2 = 500;
            if (y2 > 500) y2 = 500;

            for (int i = x1; i < x2; ++i) {
                for (int j = y1; j < y2; ++j) {
                    grid[i][j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 500; ++i) {
            for (int j = 0; j < 500; ++j) {
                if (grid[i][j]) {
                    count++;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}
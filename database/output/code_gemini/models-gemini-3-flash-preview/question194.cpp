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

    int N;
    if (!(cin >> N)) return 0;

    bool grid[105][105];
    for (int i = 0; i < 105; ++i) {
        for (int j = 0; j < 105; ++j) {
            grid[i][j] = false;
        }
    }

    for (int k = 0; k < N; ++k) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        
        for (int i = x1; i < x2; ++i) {
            for (int j = y1; j < y2; ++j) {
                grid[i][j] = true;
            }
        }
    }

    int totalArea = 0;
    for (int i = 0; i < 105; ++i) {
        for (int j = 0; j < 105; ++j) {
            if (grid[i][j]) {
                totalArea++;
            }
        }
    }

    cout << totalArea << endl;

    return 0;
}


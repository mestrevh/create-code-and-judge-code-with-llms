/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int fieldNum = 1;
    bool first = true;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        cout << "Field #" << fieldNum++ << ":\n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    cout << '*';
                } else {
                    int mineCount = 0;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            if (di == 0 && dj == 0) continue;
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (grid[ni][nj] == '*') {
                                    mineCount++;
                                }
                            }
                        }
                    }
                    cout << mineCount;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}

// Complexidade de Tempo: O(N * M) por caso de teste, onde N e M são as dimensões do campo.
// Complexidade de Espaço: O(N * M) para armazenar o grid.
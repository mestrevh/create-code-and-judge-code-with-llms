/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'o' || grid[i][j] == 'O') {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        if (r + 1 >= m) continue;

        if (grid[r + 1][c] == '.') {
            grid[r + 1][c] = 'o';
            q.push({r + 1, c});
        } else if (grid[r + 1][c] == '#') {
            int L = c, R = c;
            while (L > 0 && grid[r + 1][L - 1] == '#') L--;
            while (R < n - 1 && grid[r + 1][R + 1] == '#') R++;
            
            int start = max(0, L - 1);
            int end = min(n - 1, R + 1);
            
            for (int j = start; j <= end; ++j) {
                if (grid[r][j] == '.') {
                    grid[r][j] = 'o';
                    q.push({r, j});
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << grid[i] << "\n";
    }

    return 0;
}
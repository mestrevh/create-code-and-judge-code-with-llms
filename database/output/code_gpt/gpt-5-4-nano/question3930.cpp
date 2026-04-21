/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<string> g(m, string(n, ' '));
    for (int i = 0; i < m; i++) cin >> g[i];

    int dr[3] = {1, 1, 1};
    int dc[3] = {-1, 0, 1};

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (g[r][c] != 'O') continue;

            int curR = r, curC = c;
            while (true) {
                int nr = curR + 1;
                if (nr >= m) break;

                bool moved = false;
                for (int k = 0; k < 3; k++) {
                    int tr = nr, tc = curC + dc[k];
                    if (tc < 0 || tc >= n) continue;
                    if (g[tr][tc] == '#') continue;

                    curR = tr; curC = tc;
                    g[curR][curC] = 'o';
                    moved = true;
                    break;
                }

                if (!moved) break;
            }
            g[r][c] = 'o';
        }
    }

    for (int i = 0; i < m; i++) cout << g[i] << "\n";
    return 0;
}
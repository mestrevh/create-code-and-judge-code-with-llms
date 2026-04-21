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

    int n, tx, ty;
    if (!(cin >> n >> tx >> ty)) return 0;

    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }

    vector<vector<int>> grid(tx, vector<int>(ty));
    for (int i = 0; i < tx; ++i) {
        for (int j = 0; j < ty; ++j) {
            cin >> grid[i][j];
        }
    }

    int max_pts = 0;
    for (int i = 0; i < n; ++i) {
        int r = coords[i].first;
        int c = coords[i].second;

        if (r >= 0 && r < tx && c >= 0 && c < ty) {
            for (int team = 1; team <= 4; ++team) {
                int row_cnt = 0;
                for (int j = 0; j < ty; ++j) {
                    if (grid[r][j] == team) row_cnt++;
                }
                int col_cnt = 0;
                for (int k = 0; k < tx; ++k) {
                    if (grid[k][c] == team) col_cnt++;
                }

                int score = row_cnt + col_cnt;
                if (grid[r][c] == team) score--;

                if (score > max_pts) {
                    max_pts = score;
                }
            }
        }
    }

    cout << "A pontuacao da equipe vencedora sera " << max_pts << " ponto(s)!";

    return 0;
}
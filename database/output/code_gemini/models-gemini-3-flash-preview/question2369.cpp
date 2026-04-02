/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> mat(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            bool ok = true;
            bool has_neighbor = false;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        has_neighbor = true;
                        if (mat[i][j] >= mat[ni][nj]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                res.push_back({i, j});
            }
        }
    }

    cout << "[";
    for (size_t k = 0; k < res.size(); ++k) {
        cout << "(" << res[k].first << ", " << res[k].second << ")";
        if (k < res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
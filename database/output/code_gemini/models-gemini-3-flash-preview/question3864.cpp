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

    string dim;
    if (!(cin >> dim)) return 0;

    int m, n;
    size_t x_pos = dim.find('x');
    if (x_pos == string::npos) {
        m = dim[0] - '0';
        n = dim[dim.length() - 1] - '0';
    } else {
        m = stoi(dim.substr(0, x_pos));
        n = stoi(dim.substr(x_pos + 1));
    }

    int k;
    if (!(cin >> k)) return 0;

    if (k >= m * n) {
        cout << "BANDECLAY OVERLOAD!" << endl;
        return 0;
    }

    vector<vector<int>> grid(m, vector<int>(n, 0));
    vector<vector<bool>> isBomb(m, vector<bool>(n, false));

    for (int i = 0; i < k; ++i) {
        string coord;
        if (!(cin >> coord)) break;
        if (coord.length() < 2) continue;
        int c = coord[0] - 'a';
        int r = coord[1] - '1';
        if (r >= 0 && r < m && c >= 0 && c < n) {
            isBomb[r][c] = true;
            grid[r][c] = 9;
        }
    }

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!isBomb[r][c]) {
                int count = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = r + dr;
                        int nc = c + dc;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                            if (isBomb[nr][nc]) {
                                count++;
                            }
                        }
                    }
                }
                grid[r][c] = count;
            }
        }
    }

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}
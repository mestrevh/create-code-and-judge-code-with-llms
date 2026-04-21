/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dims;
    if (!getline(cin, dims)) return 0;
    while (dims.size() && (dims.back()=='\r' || dims.back()=='\n')) dims.pop_back();
    if (dims.empty()) return 0;

    for (char &c : dims) {
        if (c == 'x' || c == 'X') c = ' ';
    }
    stringstream ss(dims);
    int m, n;
    ss >> m >> n;

    int k;
    if (!(cin >> k)) return 0;

    vector<vector<int>> grid(m, vector<int>(n, 0));

    auto colFrom = [](char x)->int { return x - 'a'; };
    auto rowFrom = [](char y)->int { return y - '1'; };

    int maxCells = m * n;
    if (k >= maxCells) {
        cout << "BANDECLAY OVERLOAD!\n";
        return 0;
    }

    for (int i = 0; i < k; i++) {
        string pos;
        cin >> pos;
        char x = pos[0];
        char y = pos[1];
        int cx = colFrom(x);
        int cy = rowFrom(y);
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                int nx = cx + dx;
                int ny = cy + dy;
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    grid[ny][nx] += 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            if (val == 0) val = 1;
            else if (val > 9) val = 9;
            if (val > 0 && val < 9) val = val;
            grid[i][j] = val;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
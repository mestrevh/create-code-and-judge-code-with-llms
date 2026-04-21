/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int K;
    cin >> K;

    auto inside = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };

    auto getCell = [&](int r, int c) {
        if (!inside(r, c)) return ' ';
        return grid[r][c];
    };

    int pass = 0;

    for (int qi = 0; qi < K; qi++) {
        int T;
        string s;
        cin >> T >> s;

        bool pal = true;
        for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) { pal = false; break; }
        }
        if (pal) {
            pass++;
            continue;
        }

        int r = 0, c = 0;
        bool ok = true;
        for (char ch : s) {
            int nr = r, nc = c;
            if (ch == 'C') nr--;
            else if (ch == 'B') nr++;
            else if (ch == 'D') nc++;
            else if (ch == 'E') nc--;

            if (!inside(nr, nc)) { ok = false; break; }
            if (grid[nr][nc] == 'x') { ok = false; break; }
            r = nr; c = nc;
        }

        if (ok) pass++;
    }

    cout << pass;
    return 0;
}
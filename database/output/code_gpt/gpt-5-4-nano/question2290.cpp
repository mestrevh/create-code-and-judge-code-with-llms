/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    long long n;
    if (!(cin >> m)) return 0;
    cin >> n;

    vector<vector<char>> a(m, vector<char>(m));
    int sr = -1, sc = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            char ch = s.empty() ? '*' : s[0];
            a[i][j] = ch;
            if (ch == '@') {
                sr = i; sc = j;
            }
        }
    }

    long long steps = 0;
    bool gameOver = false;

    vector<pair<int,int>> dirs(256, {0,0});
    dirs['C'] = {-1, 0};
    dirs['B'] = {1, 0};
    dirs['D'] = {0, 1};
    dirs['E'] = {0, -1};

    auto wrap = [&](int &r, int &c) {
        if (r < 0) r = m - 1;
        else if (r >= m) r = 0;
        if (c < 0) c = m - 1;
        else if (c >= m) c = 0;
    };

    while (steps < n && !gameOver) {
        string s;
        cin >> s;
        char mv = s.empty() ? ' ' : s[0];

        int nr = sr + dirs[(unsigned char)mv].first;
        int nc = sc + dirs[(unsigned char)mv].second;
        wrap(nr, nc);

        char target = a[nr][nc];
        a[sr][sc] = '*';
        if (target == '#') {
            gameOver = true;
            break;
        }
        a[nr][nc] = '@';
        sr = nr; sc = nc;
        steps++;
    }

    if (gameOver) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << (j + 1 == m ? '\n' : ' ');
            }
        }
        cout << "Game over.";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << (j + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
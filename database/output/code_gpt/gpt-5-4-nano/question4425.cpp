/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int r = -1, c = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 'x') {
                r = i; c = j;
            }
        }
    }

    char ch;
    while (cin >> ch) {
        int nr = r, nc = c;
        if (ch == 'L') nc = c - 1;
        else if (ch == 'R') nc = c + 1;
        else if (ch == 'U') nr = r - 1;
        else if (ch == 'D') nr = r + 1;
        else continue;

        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            swap(a[r][c], a[nr][nc]);
            r = nr; c = nc;
        }
    }

    for (int i = 0; i < N; i++) cout << a[i] << "\n";
    return 0;
}
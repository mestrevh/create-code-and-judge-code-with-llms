/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N)) return 0;
    cin >> M;

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    int C;
    cin >> C;

    string cmd;
    cmd.reserve(C);
    for (int i = 0; i < C; i++) {
        char ch;
        cin >> ch;
        while (ch == '\n' || ch == '\r' || ch == '\t' || ch == ' ') cin >> ch;
        cmd.push_back(ch);
    }

    int X, Y;
    cin >> X >> Y;

    int dx, dy;
    for (char ch : cmd) {
        if (ch == 'D') { dx = 0; dy = 1; }
        else if (ch == 'E') { dx = 0; dy = -1; }
        else if (ch == 'C') { dx = -1; dy = 0; }
        else { dx = 1; dy = 0; }

        int nx = X + dx, ny = Y + dy;
        if (0 <= nx && nx < N && 0 <= ny && ny < M && a[nx][ny] == 1) {
            X = nx;
            Y = ny;
        }
    }

    cout << "(" << X << "," << Y << ")";
    return 0;
}
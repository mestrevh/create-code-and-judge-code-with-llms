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
    vector<int> M(N);
    for (int i = 0; i < N; i++) cin >> M[i];

    bool hole[8][8] = {};
    hole[1][3] = true;
    hole[2][3] = true;
    hole[2][5] = true;
    hole[5][4] = true;

    int dx[9], dy[9];
    dx[1] = -2; dy[1] = 1;
    dx[2] = -1; dy[2] = 2;
    dx[3] = 1;  dy[3] = 2;
    dx[4] = 2;  dy[4] = 1;
    dx[5] = 2;  dy[5] = -1;
    dx[6] = 1;  dy[6] = -2;
    dx[7] = -1; dy[7] = -2;
    dx[8] = -2; dy[8] = -1;

    int x = 4, y = 3;
    int movesDone = 0;
    for (int i = 0; i < N; i++) {
        int m = M[i];
        int nx = x + dx[m];
        int ny = y + dy[m];
        movesDone++;
        x = nx; y = ny;
        if (hole[x][y]) break;
    }

    cout << movesDone << "\n";
    return 0;
}
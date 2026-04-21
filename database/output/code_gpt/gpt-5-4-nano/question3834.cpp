/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> ops(20);
    for (int i = 0; i < 20; i++) {
        if (!(cin >> ops[i])) return 0;
    }

    const int N = 4;
    vector<vector<int>> cnt(N, vector<int>(N, 0));

    int x = 0, y = 0;
    cnt[x][y]++;

    for (int i = 0; i < 20; i++) {
        char c = ops[i];
        if (c == 'c') x--;
        else if (c == 'b') x++;
        else if (c == 'e') y--;
        else if (c == 'd') y++;
        if (x < 0) x = 0;
        if (x >= N) x = N - 1;
        if (y < 0) y = 0;
        if (y >= N) y = N - 1;
        cnt[x][y]++;
    }

    int bestX = 0, bestY = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cnt[i][j] < cnt[bestX][bestY] || (cnt[i][j] == cnt[bestX][bestY] && (i < bestX || (i == bestX && j < bestY))))
            {
                bestX = i;
                bestY = j;
            }
        }
    }

    cout << "Coordenada X:" << bestX << ", Y:" << bestY;
    return 0;
}
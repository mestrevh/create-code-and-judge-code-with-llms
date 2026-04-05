/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> a(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) cin >> a[i][j];
    }

    long long D;
    cin >> D;

    long long destroyed = 0;

    auto try_destroy = [&](int r, int c) {
        if (D == 0) return;
        if (a[r][c] == 1) {
            a[r][c] = 0;
            D--;
            destroyed++;
        }
    };

    if (L % 2 == 0) {
        for (int i = 0; i < L && D > 0; i++) {
            for (int j = 0; j < C && D > 0; j++) {
                try_destroy(i, j);
            }
        }
    } else {
        for (int j = 0; j < C && D > 0; j++) {
            for (int i = 0; i < L && D > 0; i++) {
                try_destroy(i, j);
            }
        }
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }

    long long remainingEliminations = D;
    long long remainingCells = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            if (a[i][j] == 1) remainingCells++;

    cout << remainingEliminations << " " << remainingCells << "\n";
    return 0;
}
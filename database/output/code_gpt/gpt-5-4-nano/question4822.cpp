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
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    vector<vector<bool>> mark(N, vector<bool>(N, false));
    bool changed = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 0) continue;
            int v = a[i][j];
            int len = 1;
            while (j + len < N && a[i][j + len] == v) len++;
            if (len >= 3) {
                for (int k = 0; k < len; k++) mark[i][j + k] = true;
            }
            len = 1;
            while (i + len < N && a[i + len][j] == v) len++;
            if (len >= 3) {
                for (int k = 0; k < len; k++) mark[i + k][j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mark[i][j]) {
                a[i][j] = 0;
                changed = true;
            }
        }
    }

    if (!changed) {
        cout << "Os dados est\u00e3o est\u00e1veis. Continue refinando.";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        if (i + 1 < N) cout << '\n';
    }
    return 0;
}
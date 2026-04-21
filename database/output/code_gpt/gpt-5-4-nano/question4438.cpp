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

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    int cand = -1;
    int questions = 0;

    for (int i = 1; i < n; i++) {
        if (cand == -1) cand = 0;
        questions++;
        if (a[cand][i] == 1) cand = i;
    }

    if (cand == -1) cand = 0;

    for (int i = 0; i < n; i++) {
        if (i == cand) continue;
        questions++;
        if (a[cand][i] == 0) {
            cout << "NAO HA CELEBRIDADE";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == cand) continue;
        questions++;
        if (a[i][cand] == 0) {
            cout << "NAO HA CELEBRIDADE";
            return 0;
        }
    }

    cout << cand;
    return 0;
}
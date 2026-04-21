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

    vector<vector<long long>> a(L, vector<long long>(C));
    vector<vector<long long>> b(L, vector<long long>(C));

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) cin >> a[i][j];
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) cin >> b[i][j];
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (j) cout << ' ';
            cout << a[i][j] + b[i][j];
        }
        if (i + 1 < L) cout << '\n';
    }

    return 0;
}
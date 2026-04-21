/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int R, C;
    if (!(cin >> R >> C)) return 0;
    vector<vector<long long>> a(R, vector<long long>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> a[i][j];
    }
    
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) {
            if (i) cout << ' ';
            cout << a[i][j];
        }
        if (j + 1 < C) cout << '\n';
    }
    return 0;
}
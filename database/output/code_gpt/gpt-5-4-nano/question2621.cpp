/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    vector<vector<long long>> M(T, vector<long long>(T));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) cin >> M[i][j];
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            long long val = M[j][i];
            if (val < 0) val *= 2;
            if (j) cout << ' ';
            cout << val;
        }
        if (i + 1 < T) cout << '\n';
    }

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<vector<long long>> a(M, vector<long long>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (i) cout << ' ';
            cout << a[i][j];
        }
        if (j + 1 < N) cout << '\n';
    }
    return 0;
}
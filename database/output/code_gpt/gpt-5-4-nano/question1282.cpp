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
    if (!(cin >> N >> M)) return 0;

    vector<vector<long long>> a(N, vector<long long>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    bool ok = true;

    if (N != M) {
        ok = false;
    } else {
        long long target = 0;
        for (int j = 0; j < N; j++) target += a[0][j];

        for (int i = 0; i < N && ok; i++) {
            long long s = 0;
            for (int j = 0; j < N; j++) s += a[i][j];
            if (s != target) ok = false;
        }

        for (int j = 0; j < N && ok; j++) {
            long long s = 0;
            for (int i = 0; i < N; i++) s += a[i][j];
            if (s != target) ok = false;
        }

        if (ok) {
            long long d1 = 0, d2 = 0;
            for (int i = 0; i < N; i++) {
                d1 += a[i][i];
                d2 += a[i][N - 1 - i];
            }
            if (d1 != target || d2 != target) ok = false;
        }
    }

    if (ok) cout << "A matriz recebida e magica.";
    else cout << "A matriz recebida nao e magica.";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    if (!(cin >> N)) return 0;
    if (!(cin >> M)) return 0;

    vector<vector<long long>> a(N, vector<long long>(M));
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    if (N != M) {
        cout << "A matriz nao possui traco\n";
    } else {
        long long trace = 0;
        long long secondary = 0;
        for (long long i = 0; i < N; i++) {
            trace += a[i][i];
            secondary += a[i][N - 1 - i];
        }
        cout << trace << "\n" << secondary << "\n";
    }

    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < M; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        if (i != N - 1) cout << "\n";
    }
    return 0;
}
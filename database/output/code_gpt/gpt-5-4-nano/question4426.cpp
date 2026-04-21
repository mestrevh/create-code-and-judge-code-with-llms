/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    for (int tc = 0; tc < K; tc++) {
        int N;
        cin >> N;
        vector<vector<long long>> a(N, vector<long long>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> a[i][j];

        long long target = 0;
        for (int j = 0; j < N; j++) target += a[0][j];

        bool ok = true;

        for (int i = 0; i < N && ok; i++) {
            long long sum = 0;
            for (int j = 0; j < N; j++) sum += a[i][j];
            if (sum != target) ok = false;
        }

        for (int j = 0; j < N && ok; j++) {
            long long sum = 0;
            for (int i = 0; i < N; i++) sum += a[i][j];
            if (sum != target) ok = false;
        }

        if (ok) {
            long long sum1 = 0, sum2 = 0;
            for (int i = 0; i < N; i++) {
                sum1 += a[i][i];
                sum2 += a[i][N - 1 - i];
            }
            if (sum1 != target || sum2 != target) ok = false;
        }

        cout << (ok ? "Eh quadrado magico!!!" : "Nao eh!!!");
        if (tc + 1 < K) cout << "\n";
    }
    return 0;
}
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

    vector<long long> rowSum(N, 0), colSum(M, 0);
    for (int i = 0; i < N; i++) {
        long long s = 0;
        for (int j = 0; j < M; j++) {
            s += a[i][j];
            colSum[j] += a[i][j];
        }
        rowSum[i] = s;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, rowSum[i]);
    for (int j = 0; j < M; j++) ans = max(ans, colSum[j]);

    cout << ans << "\n";
    return 0;
}
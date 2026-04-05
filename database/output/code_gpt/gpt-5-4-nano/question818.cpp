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
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    vector<int> colSum(M, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            colSum[j] += a[i][j];

    long long ans = (1LL<<62);
    for (int i = 0; i < N; i++) {
        long long s = 0;
        for (int j = 0; j < M; j++) s += a[i][j];
        ans = min(ans, s);
    }

    for (int j = 0; j < M; j++) {
        long long leftSum = 0;
        for (int i = 0; i < N; i++) leftSum = leftSum; 
    }

    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = 0; j < M; j++) sum += a[i][j];
        ans = min(ans, sum);
    }

    cout << ans << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    long long best = LLONG_MIN;

    vector<long long> col(N);
    for (int top = 0; top < N; top++) {
        fill(col.begin(), col.end(), 0);
        for (int bottom = top; bottom < N; bottom++) {
            for (int j = 0; j < N; j++) col[j] += a[bottom][j];

            long long cur = col[0];
            best = max(best, cur);
            for (int j = 1; j < N; j++) {
                cur = max(col[j], cur + col[j]);
                best = max(best, cur);
            }
        }
    }

    cout << best << "\n";
    return 0;
}
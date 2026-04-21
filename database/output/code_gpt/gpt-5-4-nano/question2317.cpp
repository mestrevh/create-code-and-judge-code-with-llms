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

    vector<vector<long long>> a(N + 1, vector<long long>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> a[i][j];
    }

    int P;
    cin >> P;
    long long sum = 0;
    for (int k = 0; k < P; k++) {
        int x, y;
        cin >> x >> y;
        sum += a[x][y];
    }

    long long T;
    cin >> T;

    double score = (double)sum / (double)T;
    cout << fixed << setprecision(2) << score << "\n";
    return 0;
}
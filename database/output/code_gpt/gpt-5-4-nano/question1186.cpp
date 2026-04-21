/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n)) return 0;
    if (!(cin >> m)) return 0;

    if (n <= 0 || m <= 0 || n != m) {
        cout << "erro";
        return 0;
    }

    int N = (int)n;
    vector<vector<long long>> a(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(cin >> a[i][j])) a[i][j] = 0;
        }
    }

    vector<long long> maxRow(N, LLONG_MIN), maxCol(N, LLONG_MIN);
    long long maxAll = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxRow[i] = max(maxRow[i], a[i][j]);
            maxCol[j] = max(maxCol[j], a[i][j]);
            maxAll = max(maxAll, a[i][j]);
        }
    }

    long long sumPosDiag = 0;
    for (int i = 0; i < N; i++) {
        if (a[i][i] > 0) sumPosDiag += a[i][i];
    }

    long long diffSecDiag = 0;
    for (int i = 0; i < N; i++) {
        diffSecDiag -= a[i][N - 1 - i];
    }
    for (int i = 0; i < N; i++) {
        diffSecDiag += a[i][N - 1 - i];
    }
    long long secDiagSum = 0;
    for (int i = 0; i < N; i++) secDiagSum += a[i][N - 1 - i];
    long long secDiagValue = secDiagSum;

    cout << "[";
    for (int i = 0; i < N; i++) {
        if (i) cout << ", ";
        cout << maxRow[i];
    }
    cout << "]\n";

    cout << "[";
    for (int i = 0; i < N; i++) {
        if (i) cout << ", ";
        cout << maxCol[i];
    }
    cout << "]\n";

    long long diagDiff = 0;
    long long primarySum = 0;
    for (int i = 0; i < N; i++) primarySum += a[i][i];
    diagDiff = primarySum - secDiagValue;

    cout << maxAll << "\n" << sumPosDiag << "\n" << diagDiff;

    return 0;
}
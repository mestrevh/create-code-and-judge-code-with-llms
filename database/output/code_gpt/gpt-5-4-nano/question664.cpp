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
    cout.setf(std::ios::fixed);
    cout << setprecision(6);

    while ( (cin >> N) ) {
        if (N == 0) break;

        vector<vector<double>> M(N + 1, vector<double>(N + 1, 0.0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) cin >> M[i][j];
        }

        int totalNodes = 2 * N - 1;
        vector<int> A(totalNodes + 1, 0), B(totalNodes + 1, 0);
        for (int k = N + 1; k <= totalNodes; k++) {
            int x, y;
            cin >> x >> y;
            A[k] = x;
            B[k] = y;
        }

        vector<vector<double>> dp(totalNodes + 1, vector<double>(N + 1, 0.0));

        for (int i = 1; i <= N; i++) dp[i][i] = 1.0;

        for (int k = N + 1; k <= totalNodes; k++) {
            int left = A[k], right = B[k];
            for (int i = 1; i <= N; i++) {
                double sum = 0.0;
                for (int j = 1; j <= N; j++) {
                    sum += dp[left][i] * dp[right][j] * M[i][j];
                }
                dp[k][i] = sum;
            }
        }

        double ans = dp[2 * N - 1][1];
        cout << ans + 1e-12 << "\n";
    }

    return 0;
}
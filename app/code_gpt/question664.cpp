/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<vector<double>> prob(N + 1, vector<double>(N + 1));
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                cin >> prob[i][j];

        vector<double> dp(2 * N);
        for (int i = 1; i <= N; ++i)
            dp[i - 1] = (i == 1) ? 1.0 : 0.0;

        for (int i = N + 1; i < 2 * N; ++i) {
            int A, B;
            cin >> A >> B;
            --A; --B;

            double winA = (A < N) ? dp[A] : dp[A - 1];
            double winB = (B < N) ? dp[B] : dp[B - 1];

            if (A < N && B < N) {
                dp[i] = winA * prob[A + 1][B + 1];
            } else if (A < N) {
                dp[i] = winA * prob[A + 1][B - N + 1];
            } else if (B < N) {
                dp[i] = winB * prob[B + 1][A - N + 1];
            } else {
                dp[i] = winA * prob[A - N + 1][B - N + 1];
            }

            if (A >= N) {
                dp[A] += dp[i] * winA; 
            }
            if (B >= N) {
                dp[B] += dp[i] * winB; 
            }
        }
        cout << fixed << setprecision(6) << dp[N - 1] << endl;
    }
    return 0;
}

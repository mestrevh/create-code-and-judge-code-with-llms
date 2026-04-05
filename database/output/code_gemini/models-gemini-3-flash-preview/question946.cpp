/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * Problem: Soma de grupos divisíveis por D
 * Strategy: Dynamic Programming
 * Complexity: O(T * Q * N * M * D), where:
 * T = number of test cases
 * Q = number of queries per case (up to 10)
 * N = number of elements (up to 200)
 * M = elements to choose (up to 10)
 * D = divisor (up to 20)
 * Max operations: ~10 * 10 * 200 * 10 * 20 = 400,000 per case.
 */

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, setNum = 1;
    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<ll> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        cout << "SET " << setNum++ << ":" << "\n";
        for (int q = 1; q <= Q; ++q) {
            int D, M;
            cin >> D >> M;

            // dp[j][rem] represents the number of ways to pick j elements
            // such that their sum modulo D is rem.
            // Using space optimization: j from M down to 1.
            ll dp[11][20];
            memset(dp, 0, sizeof(dp));

            dp[0][0] = 1;

            for (int i = 0; i < N; ++i) {
                // Pre-calculate current value modulo D to handle negative numbers
                int val = (int)((arr[i] % D + D) % D);
                
                // j goes from M down to 1 to ensure each element is used only once
                for (int j = M; j >= 1; --j) {
                    for (int r = 0; r < D; ++r) {
                        int prev_r = (r - val + D) % D;
                        dp[j][r] += dp[j - 1][prev_r];
                    }
                }
            }

            // The answer is the number of ways to pick exactly M elements
            // with a total sum divisible by D (remainder 0).
            cout << "QUERY " << q << ": " << dp[M][0] << "\n";
        }
    }

    return 0;
}
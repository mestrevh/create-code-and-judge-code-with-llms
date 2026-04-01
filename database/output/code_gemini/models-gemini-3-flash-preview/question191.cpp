/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Tradutor alienígena
 * Given an alphabet size N and a string S of transcribed numbers, 
 * find the number of ways to partition S into integers between 1 and N.
 * Constraints: |S| <= 100,000, N < 10^100.
 * Time Complexity: O(|S| * digits(N)), which is O(10^5 * 100) = O(10^7).
 * Modulo: 1,000,000,007.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N_str, S;
    // Read the maximum symbol value N and the sequence S
    if (!(cin >> N_str >> S)) return 0;

    int L = N_str.length();
    int M = S.length();
    const int MOD = 1000000007;

    /**
     * dp[i] stores the number of valid partitions for the suffix S[i...M-1].
     * sumDP[i] stores the suffix sum of dp from i to M: dp[i] + dp[i+1] + ... + dp[M].
     */
    vector<int> dp(M + 1, 0);
    vector<int> sumDP(M + 2, 0);

    // Base case: One way to partition an empty suffix
    dp[M] = 1;
    sumDP[M] = 1;
    sumDP[M + 1] = 0;

    // Iteratively compute DP from the end of the string
    for (int i = M - 1; i >= 0; --i) {
        // Leading zeros are not allowed as per the problem description.
        if (S[i] != '0') {
            long long current_dp = 0;
            
            /**
             * Case 1: Numbers with length k from 1 up to L-1.
             * Since N has L digits, any k-digit number (where k < L) starting
             * with a non-zero digit is guaranteed to be < N and >= 1.
             */
            int max_k_small = min(L - 1, M - i);
            if (max_k_small >= 1) {
                // sumDP[i+1] - sumDP[i+max_k_small+1] represents dp[i+1] + ... + dp[i+max_k_small]
                current_dp = (sumDP[i + 1] - sumDP[i + max_k_small + 1] + (long long)MOD) % MOD;
            }
            
            /**
             * Case 2: Number with length exactly k = L.
             * We must verify if the substring S[i...i+L-1] represents an integer <= N.
             */
            if (M - i >= L) {
                bool ok = true;
                for (int k = 0; k < L; ++k) {
                    if (S[i + k] < N_str[k]) {
                        ok = true; // S[i...i+L-1] < N
                        break;
                    }
                    if (S[i + k] > N_str[k]) {
                        ok = false; // S[i...i+L-1] > N
                        break;
                    }
                }
                // If substring <= N, add dp[i+L] to the current count
                if (ok) {
                    current_dp = (current_dp + dp[i + L]) % MOD;
                }
            }
            dp[i] = (int)current_dp;
        } else {
            // S[i] == '0' cannot be the start of any valid symbol
            dp[i] = 0;
        }
        // Update suffix sum for the next iteration
        sumDP[i] = (dp[i] + sumDP[i + 1]) % MOD;
    }

    // The answer is the number of valid partitions for the entire string S
    cout << dp[0] << endl;

    return 0;
}
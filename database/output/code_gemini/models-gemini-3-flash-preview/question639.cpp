/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Energia x Tempo (EDP Minimization)
 * The goal is to minimize the total EDP (Energy-Delay Product).
 * EDP is additive based on the test cases: sum(E_prog * T_prog) + sum(E_switch * T_switch).
 * State: dp[f] = minimum EDP to complete programs so far, ending in frequency f.
 * Transition: next_dp[f] = (E_pf * T_pf) + min(dp[f], min(dp[all]) + E_switch * T_switch)
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int F, P, E, A;
    // Process multiple test cases
    while (cin >> F >> P >> E >> A && (F || P || E || A)) {
        // EDP cost for switching frequency
        long long S = (long long)E * A;
        
        // EDP can reach ~5*10^9, long long is required (up to 9*10^18)
        const long long INF = 4e18; // Safe infinity that allows adding S without overflow
        vector<long long> dp(F + 1, INF);
        
        // Initial frequency is 1
        dp[1] = 0;

        for (int i = 0; i < P; ++i) {
            // Find the best EDP from the previous step to calculate switch options
            long long min_prev = INF;
            for (int j = 1; j <= F; ++j) {
                if (dp[j] < min_prev) {
                    min_prev = dp[j];
                }
            }

            vector<long long> next_dp(F + 1);
            for (int j = 1; j <= F; ++j) {
                long long Ep_f, Ap_f;
                cin >> Ep_f >> Ap_f;
                long long cost_pf = Ep_f * Ap_f;
                
                // Option 1: Stay in the same frequency j
                long long stay_cost = dp[j];
                // Option 2: Switch from the best previous frequency to j
                long long switch_cost = min_prev + S;
                
                // DP transition: current program EDP + minimum cost to be at freq j
                if (stay_cost < switch_cost) {
                    next_dp[j] = cost_pf + stay_cost;
                } else {
                    next_dp[j] = cost_pf + switch_cost;
                }
            }
            // Move to the next program
            dp = next_dp;
        }

        // The answer is the minimum EDP after executing all P programs
        long long ans = INF;
        for (int j = 1; j <= F; ++j) {
            if (dp[j] < ans) {
                ans = dp[j];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
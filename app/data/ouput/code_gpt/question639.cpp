/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int F, P, E, A;
    while (cin >> F >> P >> E >> A, F || P || E || A) {
        vector<vector<pair<int, int>>> programs(P, vector<pair<int, int>>(F));
        for (int p = 0; p < P; ++p)
            for (int f = 0; f < F; ++f)
                cin >> programs[p][f].first >> programs[p][f].second;

        vector<vector<long long>> dp(P, vector<long long>(F, LLONG_MAX));
        for (int f = 0; f < F; ++f)
            dp[0][f] = (long long)programs[0][f].first * programs[0][f].second;

        for (int p = 1; p < P; ++p) {
            for (int f = 0; f < F; ++f) {
                for (int prevF = 0; prevF < F; ++prevF) {
                    long long changeCost = (f == prevF) ? 0 : (long long)E + (long long)A;
                    long long currentEDP = (long long)programs[p][f].first * programs[p][f].second;
                    dp[p][f] = min(dp[p][f], dp[p - 1][prevF] + changeCost + currentEDP);
                }
            }
        }

        long long answer = LLONG_MAX;
        for (int f = 0; f < F; ++f)
            answer = min(answer, dp[P - 1][f]);

        cout << answer << endl;
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 18;
const int INF = 1e9;

int N;
pair<int, int> intervals[MAXN];
int dp[MAXN][2];

int main() {
    cin >> N;
    int num_teams = 1 << N;
    
    for (int i = 0; i < num_teams; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    for (int mask = 0; mask < num_teams; ++mask) {
        for (int i = 0; i < 2; ++i) {
            dp[mask][i] = INF;
        }
    }
    
    dp[0][0] = dp[0][1] = 0;
    
    for (int mask = 0; mask < num_teams; ++mask) {
        int count = __builtin_popcount(mask);
        
        if (count % 2 == 1) continue;
        
        for (int i = 0; i < num_teams; ++i) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < num_teams; ++j) {
                if (mask & (1 << j)) continue;
                
                int new_mask = mask | (1 << i) | (1 << j);
                int l = max(intervals[i].first, intervals[j].first);
                int r = min(intervals[i].second, intervals[j].second);

                if (l <= r) {
                    dp[new_mask][0] = min(dp[new_mask][0], dp[mask][0]);
                    dp[new_mask][1] = min(dp[new_mask][1], dp[mask][1]);
                } else {
                    int adjust_cost = (l - intervals[i].first) + (r - intervals[i].second) + (l - intervals[j].first) + (r - intervals[j].second);
                    if (adjust_cost <= INF) {
                        dp[new_mask][0] = min(dp[new_mask][0], dp[mask][0] + adjust_cost);
                    }
                }
            }
        }
    }
    
    int result = INF;
    for (int i = 0; i < 2; ++i) {
        result = min(result, dp[num_teams - 1][i]);
    }

    cout << result << endl;
    return 0;
}

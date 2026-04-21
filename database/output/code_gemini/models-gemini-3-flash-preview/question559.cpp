/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t_cases;
    if (!(cin >> t_cases)) return 0;

    while (t_cases--) {
        int n;
        if (!(cin >> n)) break;

        int dp[31];
        for (int i = 0; i < 31; ++i) {
            dp[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int p, w;
            cin >> p >> w;
            for (int j = 30; j >= w; --j) {
                if (dp[j - w] + p > dp[j]) {
                    dp[j] = dp[j - w] + p;
                }
            }
        }

        int g;
        if (!(cin >> g)) break;

        long long total_val = 0;
        for (int i = 0; i < g; ++i) {
            int m;
            cin >> m;
            if (m >= 0 && m <= 30) {
                total_val += dp[m];
            }
        }
        cout << total_val << "\n";
    }

    return 0;
}
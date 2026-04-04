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

    int n;
    while (cin >> n && n != 0) {
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= i; ++j) {
                int current_val = p[j] + dp[i - j];
                if (current_val > max_val) {
                    max_val = current_val;
                }
            }
            dp[i] = max_val;
        }

        cout << dp[n] << "\n";
    }

    return 0;
}
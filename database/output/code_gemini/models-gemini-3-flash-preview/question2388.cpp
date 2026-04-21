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
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_side = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            if (!(cin >> val)) break;
            if (val == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                if (dp[i][j] > max_side) {
                    max_side = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << max_side * max_side << endl;

    return 0;
}
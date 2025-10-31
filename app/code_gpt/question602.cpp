/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n > 0) {
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = 1; length <= n; ++length) {
            for (int left = 0; left <= n - length; ++left) {
                int right = left + length - 1;
                int year = n - length + 1;
                dp[left][right] = max(prices[left] * year + (left + 1 <= right ? dp[left + 1][right] : 0),
                                      prices[right] * year + (left <= right - 1 ? dp[left][right - 1] : 0));
            }
        }

        cout << dp[0][n - 1] << endl;
    }
    return 0;
}

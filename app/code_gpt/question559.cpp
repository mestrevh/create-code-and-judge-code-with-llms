/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> price(n), weight(n);
        for (int i = 0; i < n; ++i) {
            cin >> price[i] >> weight[i];
        }
        int g;
        cin >> g;
        vector<int> capacity(g);
        for (int i = 0; i < g; ++i) {
            cin >> capacity[i];
        }

        vector<int> dp(31, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 30; j >= weight[i]; --j) {
                dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
            }
        }

        int totalValue = 0;
        for (int i = 0; i < g; ++i) {
            totalValue += dp[capacity[i]];
        }

        cout << totalValue << endl;
    }
    return 0;
}

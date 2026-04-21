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

    int n, p;
    if (!(cin >> n >> p)) return 0;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<int> dp(p + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = p; j >= weights[i]; --j) {
            if (dp[j - weights[i]] + values[i] > dp[j]) {
                dp[j] = dp[j - weights[i]] + values[i];
            }
        }
    }

    int max_val = 0;
    for (int j = 0; j <= p; ++j) {
        if (dp[j] > max_val) {
            max_val = dp[j];
        }
    }

    cout << max_val << endl;

    return 0;
}
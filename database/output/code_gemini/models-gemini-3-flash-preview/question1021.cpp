/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> dp(31, 0);

    for (int i = 0; i < N; ++i) {
        int p, w;
        cin >> p >> w;
        for (int j = 30; j >= w; --j) {
            if (dp[j - w] + p > dp[j]) {
                dp[j] = dp[j - w] + p;
            }
        }
    }

    int G;
    cin >> G;
    long long total_max_value = 0;
    while (G--) {
        int mw;
        cin >> mw;
        total_max_value += dp[mw];
    }

    cout << total_max_value << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}
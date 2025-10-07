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
        int N;
        cin >> N;
        vector<int> f(N);
        for (int i = 0; i < N; i++) {
            cin >> f[i];
        }
        vector<int> dp(481, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 480; j >= f[i]; j--) {
                dp[j] = max(dp[j], dp[j - f[i]] + f[i]);
            }
        }
        cout << dp[480] << endl;
    }
    return 0;
}

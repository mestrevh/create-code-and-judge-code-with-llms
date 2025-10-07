/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string N;
    string s;
    cin >> N >> s;

    long long mod = 1000000007;
    int m = s.size();
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= 10 && i - j >= 0; ++j) {
            string sub = s.substr(i - j, j);
            if (sub[0] == '0') continue;
            long long num = stoll(sub);
            if (num > stoll(N)) continue;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    cout << dp[m] << endl;

    return 0;
}
